
BASEROM := baserom.z64

BASENAME := doraemon

BUILD_DIR := build
ROM       := $(BUILD_DIR)/$(BASENAME).z64
ELF       := $(ROM:.z64=.elf)
MAP       := $(ROM:.z64=.map)
LDSCRIPT  := $(BASENAME).ld

# OS Detection
ifeq ($(OS),Windows_NT)
$(error Native Windows is currently unsupported for building this repository, use WSL instead c:)
else
  UNAME_S := $(shell uname -s)
  ifeq ($(UNAME_S),Linux)
    DETECTED_OS = linux
    MAKE = make
    AR = ar
    VENV_BIN_DIR = bin
  endif
  ifeq ($(UNAME_S),Darwin)
    DETECTED_OS = macos
    MAKE = gmake
    AR = gar
    VENV_BIN_DIR = bin
  endif
endif

NO_COL  := \033[0m
RED     := \033[0;31m
RED2    := \033[1;31m
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
PINK    := \033[0;35m
CYAN    := \033[0;36m
WHITE    := \033[0;37m


MIPS_BINUTILS_PREFIX := mips-linux-gnu-

CC          := tools/ido/$(DETECTED_OS)/5.3/cc

AS              := $(MIPS_BINUTILS_PREFIX)as
LD              := $(MIPS_BINUTILS_PREFIX)ld
OBJCOPY         := $(MIPS_BINUTILS_PREFIX)objcopy
OBJDUMP         := $(MIPS_BINUTILS_PREFIX)objdump
NM              := $(MIPS_BINUTILS_PREFIX)nm


ASM_LIB_DIRS:= asm/libultra asm/libultra/libc asm/libultra/io asm/libultra/os asm/libultra/gu asm/libultra/audio asm/libultra/sp asm/rsp
ASM_DIRS += $(ASM_LIB_DIRS)
ASM_DIRS += asm asm/makerom asm/data
DATA_DIRS := assets assets/makerom
SRC_DIRS := $(shell find src -type d)

ICONV           := iconv
ICONV_FLAGS     := --from-code=UTF-8 --to-code=SHIFT-JIS

ASM_PROC_DIR	:= tools/asm_processor
ASM_PROC		:= python3 $(ASM_PROC_DIR)/build.py

ASM_PROC_FLAGS  := --input-enc=utf-8 --output-enc=shift-jis

OBJDUMP_FLAGS := -d -r -z -Mreg-names=32

C_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES := $(foreach dir,$(SRC_DIRS) $(ASM_DIRS),$(wildcard $(dir)/*.s))
DATA_FILES := $(foreach dir,$(DATA_DIRS),$(wildcard $(dir)/*.bin))

O_FILES := $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
           $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
           $(foreach file,$(DATA_FILES),$(BUILD_DIR)/$(file:.bin=.o)) \

# Automatic dependency files
DEP_FILES := $(O_FILES:.o=.d) \
             $(O_FILES:.o=.asmproc.d)

INCLUDE_CFLAGS = -I. -I include -I lib/libultra -I lib/libulra/libc

OPT_FLAGS 	:= -mips2 -O2 
C_FLAGS		:= -o32
AS_FLAGS	:= -EB -mtune=vr4300 -march=vr4300 -mabi=32 -I include

DEFINES := -D_LANGUAGE_C -D_FINALROM -DNDEBUG -DTARGET_N64 -D_MIPS_SZLONG=32

C_FLAGS += -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm -nostdinc -g0 -w
C_FLAGS += $(DEFINES) $(INCLUDE_CFLAGS)

LD_FLAGS   = -T $(LDSCRIPT) -T undefined_funcs_auto.txt  -T undefined_syms_auto.txt
LD_FLAGS  += -Map $(ROM).map --no-check-sections

$(BUILD_DIR)/src/libultra/os/%.o: OPT_FLAGS := -mips2 -O1
$(BUILD_DIR)/src/libultra/libc/ll.o: OPT_FLAGS := -O1 -mips3 -32


default: all

all: verify


verify: $(ROM)
	@printf "$(CYAN)%s\n$(NO_COL)" $(shell md5sum -c $(BASENAME).z64.md5)

tools:
	@make -C tools

clean:
	@$(RM) -r -f build
	@$(RM) -r -f asm
	@$(RM) -r -f assets

split:
	@python3 -m splat split ./$(BASENAME).yaml 

dirs:
	$(foreach dir,$(SRC_DIRS) $(DATA_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

postsplitdirs:
	$(foreach dir, $(ASM_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

setup: dirs split postsplitdirs

# cc & asm-processor
build/src/%.o: CC := $(ASM_PROC) $(ASM_PROC_FLAGS) $(CC) -- $(AS) $(AS_FLAGS) --


$(BUILD_DIR)/src/libultra/libc/%.o: src/libultra/libc/%.c
	@$(CC) -c $(C_FLAGS) $(OPT_FLAGS) -o $@ $<
	@printf "[$(GREEN)  ido5.3  $(NO_COL)]  $<\n"
	@$(PYTHON) tools/set_o32abi_bit.py $@
	@$(OBJDUMP) $(OBJDUMP_FLAGS) $@ > $(@:.o=.s)

$(ROM).elf: $(BASENAME).ld $(O_FILES)
	@$(LD) $(LD_FLAGS) -o $@

$(BUILD_DIR)/%.o: %.c
	@$(CC) -c $(C_FLAGS) $(OPT_FLAGS) -o $@ $<
	@printf "[$(GREEN)  ido5.3  $(NO_COL)]  $<\n"

$(BUILD_DIR)/%.o: %.s
	@$(ICONV) $(ICONV_FLAGS) $< | $(AS) $(AS_FLAGS) -o $@
	@printf "[$(RED)    GAS   $(NO_COL)]  $<\n"

$(BUILD_DIR)/%.o: %.bin
	@$(LD) -r -b binary -o $@ $<
	@printf "[$(WHITE) SEGMENTS $(NO_COL)]  $<\n"

$(ROM).bin: $(ROM).elf
	@$(OBJCOPY) -O binary --pad-to=0x800000 --gap-fill=0xFF  $< $@
	@printf "[$(CYAN)  Objcopy $(NO_COL)]  $(CYAN)$<\n"

$(ROM): $(ROM).bin
	@cp $< $@

-include $(DEP_FILES)

### Settings
.SECONDARY:
.PHONY: all clean default
SHELL = /bin/bash -e -o pipefail
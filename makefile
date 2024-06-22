
BASEROM := baserom.z64

BUILD_DIR := build
ROM       := $(BUILD_DIR)/doraemon.z64
ELF       := $(ROM:.z64=.elf)
MAP       := $(ROM:.z64=.map)
LDSCRIPT  := $(ROM:.z64=.ld)

CC          := tools/ido/$(DETECTED_OS)/5.3/cc

AS              := $(MIPS_BINUTILS_PREFIX)as
LD              := $(MIPS_BINUTILS_PREFIX)ld
OBJCOPY         := $(MIPS_BINUTILS_PREFIX)objcopy
OBJDUMP         := $(MIPS_BINUTILS_PREFIX)objdump
NM              := $(MIPS_BINUTILS_PREFIX)nm

ASM_DIRS := asm asm/libultra
DATA_DIRS := assets
SRC_DIRS := $(shell find src -type d)

C_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES := $(foreach dir,$(SRC_DIRS) $(ASM_DIRS),$(wildcard $(dir)/*.s))
DATA_FILES := $(foreach dir,$(DATA_DIRS),$(wildcard $(dir)/*.bin))

O_FILES := $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.c.o)) \
           $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.s.o)) \
           $(foreach file,$(DATA_FILES),$(BUILD_DIR)/$(file:.bin=.bin.o)) \

tools:
	make -C tools

clean:
	@rm -r asm
	@rm -r assets
	@make clean -C tools

split:
	@python3 -m splat split ./doraemon.yaml 
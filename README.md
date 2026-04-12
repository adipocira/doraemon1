# Doraemon 1 ![Static Badge](https://img.shields.io/badge/code-313%2F872-green?style=flat-square&color=%230097e3) ![Static Badge](https://img.shields.io/badge/libultra-19%2F334-green?style=flat-square&color=%23f5cc07)



**Doraemon: Nobita to Mittsu no Seireiseki** decompilation

Builds `doraemon.z64`md5: c2166455e94e89e9e3ab612b4377c443

## Building

* make
* git
* a mips toolchain
* python3

Under debian based systems :

```bash
sudo apt update
sudo apt install make git build-essential binutils-mips-linux-gnu python3
```

Under arch based systems :
```bash
sudo pacman -Syuu make git mips64-elf-binutils python3
```

Install the python dependencies using pip (requirements.txt)

---

Place the doraemon ROM at the root of the folder as `baserom.z64` 

! Recommended to run with jobs
```bash
make tools
make setup
make 
```


# Doraemon 1

**Doraemon: Nobita to Mittsu no Seireiseki** decompilation

Builds `doraemon.z64`md5: c2166455e94e89e9e3ab612b4377c443

## Building

* make
* git
* build-essential
* binutils-mips-linux-gnu
* python3

Under debian based systems :

```bash
sudo apt update
sudo apt install make git build-essential binutils-mips-linux-gnu python3
```

Install splat using pip (requirements.txt)

---

Place the doraemon ROM at the root of the folder as `baserom.z64` 

! Recommended to run with jobs
```bash
make tools
make setup
make 
```

---

#### TODO

Fix C files so IDO doesn't complain
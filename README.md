<p align="center" >
  <img src=".github/logo.png" width="175" alt="last-commit" >
</p>

# 🖥️ BitOS - Educational Operating System

<p align="center">
  <img alt="GitHub language count" src="https://img.shields.io/github/languages/count/filipebteixeira98/bit-os?color=A9A9A9&style=flat-square">
  <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/filipebteixeira98/bit-os?color=A9A9A9&style=flat-square">
  <img alt="Repository size" src="https://img.shields.io/github/repo-size/filipebteixeira98/bit-os?color=A9A9A9&style=flat-square">
  <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/filipebteixeira98/bit-os?color=A9A9A9&style=flat-square">
  <img alt="GitHub stars" src="https://img.shields.io/github/stars/filipebteixeira98/bit-os?color=A9A9A9&style=flat-square">
  <img alt="GitHub forks" src="https://img.shields.io/github/forks/filipebteixeira98/bit-os?color=A9A9A9&style=flat-square">
  <img alt="GitHub watchers" src="https://img.shields.io/github/watchers/filipebteixeira98/bit-os?color=A9A9A9&style=flat-square">
</p>

<p align="center">
  <a href="#-technologies">Technologies</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#-project">Project</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#-layout">Layout</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#-license">License</a>
</p>

<p align="center">
  <img alt="License" src="https://img.shields.io/static/v1?label=license&message=MIT&color=A9A9A9&labelColor=808090">
</p>

<p align="center">
  <img alt="bit-os" src=".github/mockup.png" width="100%">
</p>

A minimal, x86-based operating system built from scratch for learning purposes. This project demonstrates the fundamentals of low-level programming, the bootloading process, and kernel entry using **C** and **Assembly**.

## 🛠️ Project Structure
* `boot.asm`: The x86 assembly bootloader (16-bit real mode).
* `kernel.c`: The main kernel logic written in C.
* `os.bin`: The final combined OS image.

## 🚀 Getting Started

### Prerequisites
You will need the following tools installed:
* **NASM**: For assembling the bootloader.
* **GCC**: For compiling the C kernel.
* **LD**: The GNU linker.
* **QEMU**: To emulate the hardware and run the OS.

> [!IMPORTANT]
> Before building, ensure you have the necessary tools installed. On Ubuntu or Debian-based systems, run:

```bash
sudo apt install nasm gcc qemu-system-x86
```

### 🔨 Compilation & Build
Follow these steps to compile the source code and create the bootable image:

1.  **Assemble the Bootloader:**
    ```bash
    nasm -f bin boot.asm -o boot.bin
    ```

2.  **Compile the Kernel:**
    ```bash
    gcc -ffreestanding -m32 -fno-pie -fno-stack-protector -c kernel.c -o kernel.o
    ```

3.  **Link the Kernel:**
    ```bash
    ld -m elf_i386 -Ttext 0x1000 --oformat binary kernel.o -o kernel.bin
    ```

4.  **Create the OS Image:**
    ```bash
    cat boot.bin kernel.bin > os.bin
    ```

### 💻 Running the OS
To launch your operating system using the QEMU emulator, run:

```bash
qemu-system-x86_64 -drive format=raw,file=os.bin
```

## 📚 Learning Goals
* Understanding the BIOS boot sequence.
* Transitioning from Real Mode to Protected Mode.
* Writing hardware drivers (like VGA text buffers) in C.
* Memory management and linking conventions.

## 🫶 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## 📝 License

This project is under the MIT license.

<p align="center">
  Made with ♥ by me
</p>

# jumpscare-raylib

A program that plays a GIF with sound and then exits, written in pure C using [raylib](https://www.raylib.com/).

Original intention was to make a portable "jumpscare program" what would open, run a video in fullscreen and exit.

I chose raylib for its high-level abstractions over OpenGL and audio APIs, along with its strong cross-platform support. This project was also my first experience with the Make build system. The resulting Makefile allows building the program with any `video.gif` and `sound.wav` you provide and works both on windows and linux.

---

## 🛠️ Build

The Makefile builds `video` (on Linux) or `video.exe` (on Windows) in the `./build/` directory and then runs it.

- To customize: place any `video.gif` and `sound.wav` in the `./res/` directory.
- The program will run for the length of the GIF. If the sound is longer, it will be truncated.
- The binary is self-contained — both the video and audio are embedded directly into the executable.

To rm rf build directory, run:  
```sh
make clean
````

---

## Linux

1. Install raylib following [this official guide](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux).
2. Clone this repository:

   ```sh
   git clone https://github.com/AtomixFuze/jumpscare-raylib.git
   ```
3. Enter the project directory:

   ```sh
   cd jumpscare-raylib
   ```
4. Run:

   ```sh
   make
   ```

---

## 🪟 Windows Instructions (MSYS2)

There are multiple ways to set up raylib on Windows. 
You can learn about working with raylib on windows [here](https://github.com/raysan5/raylib/wiki/Working-on-Windows).

I used MSYS2 with the MinGW-w64 toolchain.
Even tho it’s not recommended by raylib, it works for this project.

> I don’t have full instructions for setting up raylib from a clean MSYS2 install, you will need to update msys2, install build essentials, etc.

1. Install raylib:

   ```sh
   pacman -S mingw-w64-x86_64-raylib
   ```
2. Install `xxd` (provided by Vim):

   ```sh
   pacman -S vim
   ```
3. Ensure you have `git` and `make` installed.
4. Clone the repository:

   ```sh
   git clone https://github.com/AtomixFuze/jumpscare-raylib.git
   ```
5. Enter the project directory:

   ```sh
   cd jumpscare-raylib
   ```
6. Run:

   ```sh
   make
   ```

---

## 🎬 Default Assets

This repository includes the Foxy jumpscare from Five Nights at Freddy's 2 as the default `video.gif` and `sound.wav`.
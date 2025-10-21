
# OpenGLProject

Minimal cross-platform OpenGL starter using **CMake**, **GLFW**, and **GLAD**.  
Works on **Linux**, **macOS**, and **Windows (MSVC/Visual Studio)**.

## Requirements

- A C++17 compiler  
  - Linux: `g++`/`clang++`  
  - macOS: Xcode command line tools (`clang++`)  
  - Windows: **Visual Studio 2019/2022** (Desktop C++ workload) or **Build Tools**
- **CMake ≥ 3.20**
- **Git** (CMake fetches dependencies at configure time)
- Internet access during the first configure (to download GLFW/GLAD with CMake’s FetchContent)

> **Note:** You do *not* need to preinstall GLFW or GLAD—this project downloads/builds them inside the build tree.

## Quick Start (works on all platforms)

From the project root:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j
./build/OpenGLProject
```

Windows:
```bash
.␈uild\Debug\OpenGLProject.exe
```

## OS-specific Notes

### Linux (Debian/Ubuntu)
```bash
sudo apt update
sudo apt install -y build-essential cmake git   libx11-dev libxrandr-dev libxi-dev libxxf86vm-dev   libwayland-dev wayland-protocols xorg-dev
```

### macOS
```bash
brew install cmake git
xcode-select --install
```

### Windows (Visual Studio)
1. Install Visual Studio 2022 with Desktop C++ workload.
2. Open "x64 Native Tools Command Prompt for VS".
3. Run:
```bat
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --config Debug
.␈uild\Debug\OpenGLProject.exe
```

## "One-liner" like make
Add this to your shell rc:
```bash
function cmrun() {
  cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug &&   cmake --build build -j &&   ( [ -x ./build/OpenGLProject ] && ./build/OpenGLProject ||     [ -x ./build/Debug/OpenGLProject.exe ] && ./build/Debug/OpenGLProject.exe || true )
}
```

Then just run:
```bash
cmrun
```

## Project Structure

```
OpenGLProject/
├─ CMakeLists.txt
├─ include/
└─ src/
   └─ main.cpp
```

## Common Issues
- Install missing Linux dev packages if you see X11/Wayland link errors.
- Ensure cmake is installed and in PATH.
- On macOS, OpenGL 3.3 core profile deprecation warnings are normal.

## Clean build
```bash
cmake --build build --target clean
# or
rm -rf build/
```

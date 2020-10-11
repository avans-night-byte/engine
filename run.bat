@echo off

rem This script attempts to build and run the project for Windows.
rem See https://github.com/avans-night-byte/engine/wiki/Project-Setup-%5BWindows%5D for manual setup.
rem Dependencies: make, cmake, gcc/g++, git

rem 1. Pull/Update gitmodules
git submodule update --init --recursive  --remote

rem 2. Generate a makefile and buildfolder
cmake -S . -B ./build -G "MinGW Makefiles"
cd build

rem 3. Create a binary
make
cd bin

rem 4. Run the executable
NightByte.exe

pause

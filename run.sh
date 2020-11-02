#!/bin/bash
# This script attempts to build and run the project for Linux.
# See https://github.com/avans-night-byte/engine/wiki/Project-Setup-%5BLinux%5D for manual setup.
# Dependencies: make, cmake, gcc/g++, git

# 1. Pull/Update gitmodules
git submodule update --recursive --init --remote

# 2. Generate a makefile and buildfolder
cmake -S . -B ./build/
cd build

# 3. Create a binary
make
cd bin

# 4. Run the executable
./NightByte

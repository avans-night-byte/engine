#!/bin/bash
# This script attempts to build and run the project for Linux.
# See https://github.com/avans-night-byte/engine/wiki/Project-Setup-%5BLinux%5D for manual setup.
# Dependencies: make, cmake, gcc/g++, git

# 1. Pull/Update gitmodules
git submodule update --recursive --init --remote

# 2. Box2D Installation
cd Libraries/Box2D
mkdir build
cd build
cmake -DBOX2D_BUILD_EXAMPLES=OFF -DBOX2D_BUILD_DOCS=ON ..
cmake --build .
sudo make install
cd ../../../

# 3. Generate a makefile and buildfolder
cmake -S . -B ./build/
cd build

# 4. Create a binary
make
cd bin

# 5. Run the executable
./NightByte

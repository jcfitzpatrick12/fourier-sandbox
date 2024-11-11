#!/bin/bash

# Clean previous build directory if it exists
rm -rf build
# Create a new build directory
mkdir build
# Navigate to the build directory
cd build
# Run CMake configuration step
cmake ..
# Build the project
make
# Navigate back to the project root directory
cd ..
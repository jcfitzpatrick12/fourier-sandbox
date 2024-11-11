cmake_minimum_required(VERSION 3.10)
project(FourierSeries)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for headers
include_directories(include)

# Collect source files
file(GLOB SOURCES "src/*.cpp")

# Create an executable from the sources
add_executable(run_me ${SOURCES})
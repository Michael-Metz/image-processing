cmake_minimum_required(VERSION 3.6)   # CMake version check
project(image-processing)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard

add_executable(src/ImageGrayscale8Bit.cpp src/ImageIO.cpp src/OtsuDriver.cpp) #otsu method program
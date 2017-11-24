cmake_minimum_required(VERSION 3.8)
project(AAL)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp InputOutput.cpp InputOutput.h Generator.cpp Generator.h Alghoritms.cpp Alghoritms.h Worker.cpp Worker.h cxxopts.hpp)
add_executable(AAL ${SOURCE_FILES})
add_executable(Gen Gen.cpp Generator.h Generator.cpp cxxopts.hpp)
#!/bin/bash
rm -rf ./CMakeFiles
rm ./CMakeCache.txt
rm ./cmake_install.cmake
rm ./Makefile
rm antlr4-example
cmake ..
make

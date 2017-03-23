#!/bin/bash
rm -rf ./CMakeFiles
rm -rf ./temp
cmake ..
mkdir temp
cp ./CMakeFiles/antlr4-example.dir/depend.make ./temp/depend.make 
make

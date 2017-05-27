#!/bin/bash
rm -rf ../src/CMakeFiles
rm -rf ../src/temp
cmake ..
mkdir temp
cp ./CMakeFiles/JWB.dir/depend.make ./temp/depend.make
make
./JWB ../testExamples/testInh

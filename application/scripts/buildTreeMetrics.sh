#!/bin/bash
rm -rf ./CMakeFiles
rm -rf ./temp
cmake ..
mkdir temp
cp ./CMakeFiles/JWB.dir/depend.make ./temp/depend.make
make
./JWB ../testExamples/InheritanceFactorTest.java
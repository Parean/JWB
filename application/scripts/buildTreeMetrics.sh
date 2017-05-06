#!/bin/bash
rm -rf ./CMakeFiles
rm -rf ./temp
# cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=/usr/local/bin/gcc-5 -DCMAKE_CXX_COMPILER=/usr/local/bin/g++-5 ..
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ ..
mkdir temp
cp ./CMakeFiles/JWB.dir/depend.make ./temp/depend.make
make
./JWB ../testExamples/InheritanceFactorTest.java
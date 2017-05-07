#!/bin/bash
rm ./CMakeFiles/JWB.dir/depend.make
rm ./CMakeFiles/JWB.dir/depend.internal
rm ./CMakeFiles/JWB.dir/CXX.includecache
rm -r ./CMakeFiles/JWB.dir/src/*.o
cp ./temp/depend.make ./CMakeFiles/JWB.dir/
rm JWB
make
./JWB ../testExamples/InheritanceFactorGenericTest.java

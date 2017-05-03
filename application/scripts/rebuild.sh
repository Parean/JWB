#!/bin/bash
rm ./CMakeFiles/JWB.dir/depend.make
rm ./CMakeFiles/JWB.dir/depend.internal
rm ./CMakeFiles/JWB.dir/CXX.includecache
rm ./CMakeFiles/JWB.dir/*.o
cp ./temp/depend.make ./CMakeFiles/JWB.dir/
rm JWB
make
./JWB ../testExamples/Clustering/example2.java

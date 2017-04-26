#!/bin/bash
rm ./CMakeFiles/JWB.dir/depend.make
rm ./CMakeFiles/JWB.dir/depend.internal
rm ./CMakeFiles/JWB.dir/CXX.includecache
rm ./CMakeFiles/JWB.dir/сustomListener.o
rm ./CMakeFiles/JWB.dir/interfaceDescription.o
rm ./CMakeFiles/JWB.dir/classDescription.o
rm ./CMakeFiles/JWB.dir/methodDescription.o
rm ./CMakeFiles/JWB.dir/metricsCalculator.o
cp ./temp/depend.make ./CMakeFiles/JWB.dir/
rm JWB
make
./JWB ../testExamples/InheritanceFactorTest.java
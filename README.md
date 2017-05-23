# Project Java Wet Blanket
The guy who spoils all the fun.

## Brief description
JWB (hereinafter Project Java Wet Blanket) analyzis Java sourse code with various OOP metrics. 
One can eighter use JWB as console application or use it as a library.
List of the metrics that are supported lies in docs directory (currently empty, but metrics exists).
If you want to use JWB as a library, import JWB::neededMetricCalculator.

JWB currently supports only Linux/MacOs.

## Dependency list
* [CMake](https://cmake.org)
* [tar](https://www.gnu.org/software/tar/tar.html) and [bzip2](http://www.bzip.org) (used to unpack boost archive) 
* [Boost library](http://www.boost.org) (boost::optional and boost::filesystem; they should be added to 17th C++ standart).

## Installation guide
Firstly, install CMake
```
$ sudo apt-get install cmake
```

Then, clone our repo and run buildJWB.sh
```
$ git clone https://github.com/Parean/JWB.git
$ ./buildJWB.sh 
```

Now you shall be ready to go. Happy hacking.
## How to use
If you need to use JWB as binary then after build it should be located in application/ directory.

At this point, the application allows simple clustering of the source code. Run JWB on the project, and it will give you the optimal splitting of methods.

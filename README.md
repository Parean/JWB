# Project Java Wet Blanket
The guy who spoils all the fun.

## Brief description
JWB (hereinafter Project Java Wet Blanket) analyzis Java sourse code with various OOP metrics. 
One can eighter use JWB as console application or use it as a library.
List of the metrics that are supported lies in docs directory (currently empty, but metrics exists).
If you want to use JWB as a library, import JWB::neededMetricCalculator.

JWB currently supports only Linux/MacOs.

## Dependency list
* [Antlr4 library](https://github.com/antlr/antlr4) to generate Java sourse code parser in C++.
* [Boost library](http://www.boost.org) (boost::optional and boost::filesystem; they should be added to 17th C++ standart).

## Installation guide
Firstly, install Antlr4 into your system (your can remove it any time after installation)
```
$ cd /usr/local/lib
$ curl -O http://www.antlr.org/download/antlr-4.6-complete.jar
```
Then update your CLASSPATH and add some aliases.
```
$ export CLASSPATH=".:/usr/local/lib/antlr-4.6-complete.jar:$CLASSPATH"
$ alias antlr4='java -Xmx500M -cp "/usr/local/lib/antlr-4.6-complete.jar:$CLASSPATH" org.antlr.v4.Tool'
$ alias grun='java org.antlr.v4.gui.TestRig'
```
Now you shall be ready clone our repo
```
git clone https://github.com/Parean/JWB.git
```
Now we need to generate antlr4 runtime library and generate C++ parser
```
$ cd antlr4-cpp-runtime-4.6-source
$ mkdir build && mkdir run && cd build
$ cmake ..
$ make
$ DESTDIR=$(pwd)/../run make install
cd ../..
```
Now build boost.
You can eighter run ./build.sh, located in boost directory, or procede with following commands, that are the exact copy.
```
cd boost
$ tar --bzip2 -xf ./boost_1_64_0.tar.bz2
$ cd boost_1_64_0
$ ./bootstrap.sh --with-libraries=filesystem
$ ./b2
cd ../..
```
To intall JWB simply run the following
```
./application/scripts/build.sh
```
Now you shall be ready to go. Happy hacking.

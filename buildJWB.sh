cd antlr4-cpp-runtime-4.6-source
mkdir build && mkdir run && cd build
cmake ..
make
DESTDIR=$(pwd)/../run make install

cd ../../boost
echo Unpacking the archive...
tar --bzip2 -xf ./boost_1_64_0.tar.bz2
cd boost_1_64_0
./bootstrap.sh --with-libraries=filesystem
./b2

cd ../../application/scripts/ && ./build.sh
mv ./JWB ../

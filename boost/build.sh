echo Unpacking the archive...
tar --bzip2 -xf ./boost_1_64_0.tar.bz2
cd boost_1_64_0
./bootstrap.sh --with-libraries=filesystem
./b2

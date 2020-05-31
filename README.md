# Project clio-test

Test binary for libclio.

## Building

You will need the following packages:
~~~~
$ sudo apt-get install build-essential autoconf libtool
~~~~

Then run the following to build (replacing CPPFLAGS with your include folder):
~~~~
$ autoreconf -vfi
$ ./configure CPPFLAGS="-I/usr/local/include/clio"
$ make
~~~~

For cross compilation pass in your toolchain via HOST option:
~~~~
$ autoreconf -vfi
$ ./configure --host=arm-linux-gnueabihf CPPFLAGS="-I/usr/local/include/clio"
$ make
~~~~


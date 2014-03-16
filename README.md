# Hexadecimal & Binary Encoder / Decoder by Braden Best

Usage examples
--------------

* Hex Encoder:

    $ hexencode [string]
    $ echo [string] | hexencode
    $ hexencode < [file]
    $ fhexencde [file]

* Hex Decoder:

    $ hexdecde [string]
    $ echo [string] | hexdecode
    $ hexdecode < [file]
    $ fhexdecode [file]
  

* Binary Encoder:

    $ binencode [string]
    $ echo [string] | binencode
    $ binencode < [file]
    $ fbinencode [file]

* Binary Decoder:

    $ bindecde [string]
    $ echo [string] | bindecode
    $ bindecode < [file]
    $ fbindecode [file]


To compile
------------
    $ make

Compile and Install
-------------------
    $ make install

Uninstall
---------
    $ make uninstall

Other information
-----------------
I have 4 main files: `hexencode.c`, `hexdecode.c`, `binencode.c`, and `bindecode.c`. They form the "engine"

The rest is input handling (`main.c`), and using the preprocessor to compile the different binaries from one file.

Most of the work is left up to the compiler, so using the included `Makefile` is strongly recommended.

This uses GCC and GNU Make, so your best bet compiling it is with those two programs.

If you're compiling with a different compiler (e.g. Visual Studio's compiler (Windows)), then read the Makefile to understand how you should compile for each executable.

Then again, if you understand Makefiles, then you'd probably be using MinGW, or more likely GCC on Linux

Either way, this is written to be portable. No specific OS dependencies are used. So I can't see why it wouldn't compile, given the right development environment.

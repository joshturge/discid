#!bin/bash

# Download and install libdiscid 
git clone https://github.com/metabrainz/libdiscid
cd libdiscid
mkdir _build; cd _build
cmake ..
make
make check
make install
cd ../..

# Build
gcc -I/usr/local/include -L/usr/local/lib -ldiscid -Wl,-R/usr/local/lib main.c -o discid
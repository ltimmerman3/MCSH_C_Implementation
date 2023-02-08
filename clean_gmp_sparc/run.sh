cd src
make clean
make -j
cd ..
cp ./lib/gmp ./test
cd ./test
./gmp Al
cd ..

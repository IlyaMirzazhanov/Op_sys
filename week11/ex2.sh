#!/usr/bin/bash

mkdir -p lofsdisk/bin
mkdir -p lofsdisk/lib64
mkdir -p lofsdisk/usr/lib
mkdir -p lofsdisk/usr/lib64
cp /bin/bash lofsdisk/bin
cp lofsdisk/usr/lib/* lofsdisk/lib
cp lofsdisk/usr/lib64/* lofsdisk/lib64
sudo chmod 777 ./lofsdisk
echo 'Ilya' > lofsdisk/file1
echo 'Mirzazhanov' > lofsdisk/file2
gcc ex2.c -o ex2.out
cp ex2.out lofsdisk
sudo chroot lofsdisk /ex2.out > ex2.txt
./ex2.out >> ex2.txt


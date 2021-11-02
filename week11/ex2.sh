#!/bin/bash
sudo chmod 777 ./lofsdisk
sudo echo 'Ilya' >> file1.txt
sudo echo 'Mirzazhanov' >> file2.txt
gcc ex2.c -o ex2.out
cp ex2.out lofsdisk
sudo chroot lofsdisk /ex2.out > ex2.txt
./ex2.out >> ex2.txt

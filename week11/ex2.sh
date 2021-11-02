#!/bin/bash
sudo chmod 777 ./lofsdisk
sudo echo 'Ilya' >> file1.txt
sudo echo 'Mirzazhanov' >> file2.txt
gcc ex2.c -o ex2
sudo chroot ./lofsdisk
#!/bin/bash
fallocate -l 50M lofs.img
sudo losetup -f lofs.img
mkdir lofsdisk
sudo mkfs.ext4 /dev/loop6
sudo mount /dev/loop6
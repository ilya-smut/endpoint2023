#!/bin/bash
yasm -f elf64 $1.asm
ld -o $1 $1.o
echo 'program has been compiled'

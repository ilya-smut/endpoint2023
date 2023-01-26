#!/bin/bash
yasm -f elf64 print.asm
ld -o print print.o
echo 'print.asm has been compiled'

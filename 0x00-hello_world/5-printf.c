#!/bin/bash
echo '#include <stdio.h> ; int main() { printf("with proper grammar, but the outcome is a piece of art,\n"); return 0; }' > program.c && gcc -Wall program.c -o program && ./program


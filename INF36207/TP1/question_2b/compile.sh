#!/bin/sh

echo "\033[32m" "Compiling [NO-DEBUG] binary" "\033[0m"
make

echo ""
echo "\033[32m" "Cleaning directory" "\033[0m"
make clean

echo ""
echo "\033[32m" "Compiling [DEBUG] binary" "\033[0m"
make debug

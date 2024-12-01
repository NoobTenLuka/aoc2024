#!/bin/sh
mkdir -p out
g++ -std=c++11 -O2 -Wall day$1.cpp -o ./out/day$1
./out/day$1

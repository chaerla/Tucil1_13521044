#!/bin/bash
cd src
g++ main.cpp utils.cpp permutation.cpp solver.cpp -o ../bin/main
../bin/main
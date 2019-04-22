#!/bin/bash

# cd mnt/5932357A1CFE5229/'OneDrive - University of Colorado at Boulder Office 365'/'OneDrive - UCB-O365'/2019/CSCI\ 2270/Project/CSCI_2270_Project
swig -java -c++ -package mypackage -outdir Java_experimenting/mypackage/ -o swig.cpp swig.i
make clean
cd Java_experimenting/mypackage
./compile.sh
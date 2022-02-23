#!/usr/bin/bash

for i in {1..2}
do
    gcc -o cycle$i cycle$i.c
    rm cycle$i.csv
    for j in {1..10000}
    do
        ./cycle$i $j >> "cycle$i.csv"
    done
    rm cycle$i
done

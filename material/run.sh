#!/bin/bash

g++ material.cpp -o material.exe

for iter in {0..2}
do
	for star in {16..22}
	do
		OutFile="./exec/out$star$iter.txt"
		echo $OutFile
		bash ./calc.sh $star $iter $OutFile
	done
done
#!/bin/bash

From=$1
To=$2
num=$3

levels="140 150 160 200"

g++ meso.cpp -o meso.exe

for iter in {0..7}
do
	Thirtyoff=$(($iter%2))
	SuccessOnFives=$(($iter/2%2))
	Safeguard=$(($iter/4%2))
	for level in $levels
	do
		OutFile="./exec/out$To$Thirtyoff$SuccessOnFives$Safeguard$num$level.txt"
		echo $OutFile
		bash ./calc.sh $From $To $Thirtyoff $SuccessOnFives $Safeguard $num $OutFile $level
	done
done
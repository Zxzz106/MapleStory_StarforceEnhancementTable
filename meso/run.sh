#!/bin/bash

From=12
To=$1
num=$2

levels="140 150 160 200"

for iter in {0..7}
do
	Thirtyoff=$(($iter%2))
	SuccessOnFives=$(($iter/2%2))
	Safeguard=$(($iter/4%2))
	for level in $levels
	do
		OutFile="./meso/exec/out$To$Thirtyoff$SuccessOnFives$Safeguard$num$level.txt"
		echo $OutFile
		bash ./meso/calc.sh $From $To $Thirtyoff $SuccessOnFives $Safeguard $num $OutFile $level
	done
done
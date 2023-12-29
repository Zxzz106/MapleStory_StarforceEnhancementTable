#!/bin/bash

From=12
To=22
num=60000

for iter in {0..7}
do
	Thirtyoff=$(($iter%2))
	SuccessOnFives=$(($iter/2%2))
	Safeguard=$(($iter/4%2))
	OutFile="out$Thirtyoff$SuccessOnFives$Safeguard.txt"
	echo $OutFile
	bash ./calc.sh $From $To $Thirtyoff $SuccessOnFives $Safeguard $num $OutFile
done
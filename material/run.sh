#!/bin/bash

star=$1
Material=$2

for iter in {0..2}
do
	OutFile="./meso/exec/out$star$iter.txt"
	echo $OutFile
	bash ./material/calc.sh $star $iter $Material $OutFile
done
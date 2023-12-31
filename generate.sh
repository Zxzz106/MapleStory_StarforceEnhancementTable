#!/bin/bash

star=22
Material=20
Meso=60

mkdir ./material/exec
mkdir ./meso/exec
mkdir ./mmp/exec
mkdir ./mmp/output

g++ ./material/material.cpp -o ./material/material.exe
g++ ./meso/meso.cpp -o ./meso/meso.exe

bash ./material/run.sh $star $Material
bash ./meso/run.sh $star $Meso
python3 mmp.py
python3 splice.py

mv ./mmp/output ./
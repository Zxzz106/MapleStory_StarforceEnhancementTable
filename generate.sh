#!/bin/bash

star=18
Material=20
Meso=60

mkdir ./material/exec
mkdir ./meso/exec
mkdir ./mmp/exec
mkdir ./output

g++ ./material/material.cpp -o ./material/material.exe
g++ ./meso/meso.cpp -o ./meso/meso.exe

bash ./material/run.sh $star $Material
python3 ./material/make_csv.py
bash ./meso/run.sh $star $Meso
python3 ./meso/make_csv.py
python3 ./mmp/mmp.py
python3 ./mmp/splice.py

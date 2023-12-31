star=$1
type=$2
Material=$3
OutFile=$4

echo $star $type $Material > in.txt

./material/material.exe < in.txt > $OutFile

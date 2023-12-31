From=$1
To=$2
Thirtyoff=$3
SuccessOnFives=$4
Safeguard=$5
num=$6
OutFile=$7
level=$8

num=$(( $num*1000 ))

echo $Thirtyoff $SuccessOnFives $Safeguard > in.txt
echo $From $To >>in.txt
echo $level >> in.txt
echo $num >> in.txt

./meso/meso.exe < in.txt > $OutFile

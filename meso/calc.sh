From=$1
To=$2
Thirtyoff=$3
SuccessOnFives=$4
Safeguard=$5
num=$6
OutFile=$7
level=$8

# echo "From $From to $To" > $OutFile
# if [[ $Thirtyoff -eq 1 ]]; then echo -n "七折 " >> $OutFile; fi
# if [[ $SuccessOnFives -eq 1 ]]; then echo -n "必成 " >> $OutFile; fi
# if [[ $Thirtyoff -eq 0 && $SuccessOnFives -eq 0 ]]; then echo -n "无活动 " >> $OutFile; fi
# if [[ $Safeguard -eq 1 ]]; then echo -n "保护 " >> $OutFile; fi
# echo "" >> $OutFile

# echo "From $From to $To, level $i" >> $OutFile

num=$(( $num*1000 ))

echo $Thirtyoff $SuccessOnFives $Safeguard > in.txt
echo $From $To >>in.txt
echo $level >> in.txt
echo $num >> in.txt

./meso.exe < in.txt > $OutFile

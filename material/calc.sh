star=$1
type=$2
OutFile=$3

# echo "From $From to $To" > $OutFile
# if [[ $Thirtyoff -eq 1 ]]; then echo -n "七折 " >> $OutFile; fi
# if [[ $SuccessOnFives -eq 1 ]]; then echo -n "必成 " >> $OutFile; fi
# if [[ $Thirtyoff -eq 0 && $SuccessOnFives -eq 0 ]]; then echo -n "无活动 " >> $OutFile; fi
# if [[ $Safeguard -eq 1 ]]; then echo -n "保护 " >> $OutFile; fi
# echo "" >> $OutFile

# echo "From $From to $To, level $i" >> $OutFile

echo $star $type > in.txt

./material.exe < in.txt > $OutFile

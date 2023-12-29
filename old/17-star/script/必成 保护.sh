echo "必成 保护" > out011.txt

echo "From 12 to 17, lvl140" >> out011.txt
for num in {0..4000..100}
do
echo 0 1 1 > in.txt
echo 12 17 >>in.txt

echo 140 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out011.txt
done

echo "From 12 to 17, lvl150" >> out011.txt
for num in {0..4000..100}
do
echo 0 1 1 > in.txt
echo 12 17 >>in.txt

echo 150 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out011.txt
done

echo "From 12 to 17, lvl160" >> out011.txt
for num in {0..4000..100}
do
echo 0 1 1 > in.txt
echo 12 17 >>in.txt

echo 160 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out011.txt
done

echo "From 12 to 17, lvl200" >> out011.txt
for num in {0..4000..100}
do
echo 0 1 1 > in.txt
echo 12 17 >>in.txt

echo 200 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out011.txt
done

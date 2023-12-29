echo "超必 保护" > out111.txt

echo "From 12 to 17, lvl140" >> out111.txt
for num in {0..4000..100}
do
echo 1 1 1 > in.txt
echo 12 17 >>in.txt

echo 140 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out111.txt
done

echo "From 12 to 17, lvl150" >> out111.txt
for num in {0..4000..100}
do
echo 1 1 1 > in.txt
echo 12 17 >>in.txt

echo 150 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out111.txt
done

echo "From 12 to 17, lvl160" >> out111.txt
for num in {0..4000..100}
do
echo 1 1 1 > in.txt
echo 12 17 >>in.txt

echo 160 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out111.txt
done

echo "From 12 to 17, lvl200" >> out111.txt
for num in {0..4000..100}
do
echo 1 1 1 > in.txt
echo 12 17 >>in.txt

echo 200 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out111.txt
done

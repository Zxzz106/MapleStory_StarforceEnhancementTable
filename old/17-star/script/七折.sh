echo "七折" > out100.txt

echo "From 12 to 17, lvl140" >> out100.txt
for num in {0..4000..100}
do
echo 1 0 0 > in.txt
echo 12 17 >>in.txt

echo 140 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out100.txt
done

echo "From 12 to 17, lvl150" >> out100.txt
for num in {0..4000..100}
do
echo 1 0 0 > in.txt
echo 12 17 >>in.txt

echo 150 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out100.txt
done

echo "From 12 to 17, lvl160" >> out100.txt
for num in {0..4000..100}
do
echo 1 0 0 > in.txt
echo 12 17 >>in.txt

echo 160 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out100.txt
done

echo "From 12 to 17, lvl200" >> out100.txt
for num in {0..4000..100}
do
echo 1 0 0 > in.txt
echo 12 17 >>in.txt

echo 200 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out100.txt
done

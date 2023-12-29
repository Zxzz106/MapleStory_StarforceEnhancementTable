echo "超必" > out110.txt

echo "From 12 to 17, lvl140" >> out110.txt
for num in {0..20000..500}
do
echo 1 1 0 > in.txt
echo 12 20 >>in.txt

echo 140 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out110.txt
done

echo "From 12 to 17, lvl150" >> out110.txt
for num in {0..20000..500}
do
echo 1 1 0 > in.txt
echo 12 20 >>in.txt

echo 150 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out110.txt
done

echo "From 12 to 17, lvl160" >> out110.txt
for num in {0..20000..500}
do
echo 1 1 0 > in.txt
echo 12 20 >>in.txt

echo 160 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out110.txt
done

echo "From 12 to 17, lvl200" >> out110.txt
for num in {0..20000..500}
do
echo 1 1 0 > in.txt
echo 12 20 >>in.txt

echo 200 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out110.txt
done

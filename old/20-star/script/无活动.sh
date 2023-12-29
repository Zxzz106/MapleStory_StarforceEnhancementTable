echo "无活动" > out000.txt

echo "From 12 to 17, lvl140" >> out000.txt
for num in {0..20000..500}
do
echo 0 0 0 > in.txt
echo 12 20 >>in.txt

echo 140 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out000.txt
done

echo "From 12 to 17, lvl150" >> out000.txt
for num in {0..20000..500}
do
echo 0 0 0 > in.txt
echo 12 20 >>in.txt

echo 150 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out000.txt
done

echo "From 12 to 17, lvl160" >> out000.txt
for num in {0..20000..500}
do
echo 0 0 0 > in.txt
echo 12 20 >>in.txt

echo 160 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out000.txt
done

echo "From 12 to 17, lvl200" >> out000.txt
for num in {0..20000..500}
do
echo 0 0 0 > in.txt
echo 12 20 >>in.txt

echo 200 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out000.txt
done

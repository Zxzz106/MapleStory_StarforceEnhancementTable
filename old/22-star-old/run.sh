echo "From 12 to 17, lvl140" > out.txt
for num in {0..2000..100}
do
echo 12 >in.txt
echo 17 >> in.txt
echo 140 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out.txt
done

echo "From 12 to 17, lvl150" >> out.txt
for num in {0..2000..100}
do
echo 12 >in.txt
echo 17 >> in.txt
echo 150 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out.txt
done

echo "From 12 to 17, lvl160" >> out.txt
for num in {0..2000..100}
do
echo 12 >in.txt
echo 17 >> in.txt
echo 160 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out.txt
done

echo "From 12 to 17, lvl200" >> out.txt
for num in {0..2000..100}
do
echo 12 >in.txt
echo 17 >> in.txt
echo 200 >> in.txt
echo $num >> in.txt
./a.out < in.txt >> out.txt
done

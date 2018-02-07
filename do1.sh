rm test.txt
mv test.cx test.c
./do2.sh
rm test
mv test.c test.cx

mv test2.cx test.c
./do2.sh
rm test
mv test.c test2.cx

mv test3.cx test.c
./do2.sh
rm test
mv test.c test3.cx

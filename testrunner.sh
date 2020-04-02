#!/bin/bash
make

for j in 0
do
    for (( i = 1; i <= 6; i++))
    do 
        ./mstdriver < t$j$i/test.in > test.out
        echo TEST $j$i RESULT --------
        diff test.out t$j$i/test.out | cat -t -E -T -A
    done
done    

for (( i = 1; i <= 6; i++))
do 
    ./mstdriver < test0$i/test.in > test.out
    echo PERSONAL TEST 0$i RESULT --------
    diff test.out test0$i/test.out | cat -t -E -T -A
done

rm test.out
make clean






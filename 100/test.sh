#!/bin/sh

exe="a.out"
out="result"
oj_opt="-lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE"
my_opt="-Wall"

gcc $oj_opt $my_opt main.c -o $exe && \
    ./$exe < input > $out && \
    diff $out output

if [ $? -eq 0 ]; then
    echo "pass"
fi

if [ -e $out ]; then
    rm $out
fi

if [ -e $exe ]; then
    rm $exe
fi

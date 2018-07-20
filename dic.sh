#!/bin/bash
echo $1
#b= '{1,'$1'\}'
#echo $b
grep -o -w '\w\{1,'$1'\}' words.txt > temp.txt
b=$(($1-1))
echo $b
echo $"$b"
for i in $b; do
	#g=$(($i+1))
	g=$"$(($i+1))"
	echo "${g}"
	grep ${g} temp.txt>>fin.txt
done
sort -u fin.txt >>fine.txt

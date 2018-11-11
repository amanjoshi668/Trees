#!/bin/bash
m=10
n=3
while ((m<50000000))
do
	echo "$n $m" | ./kruskal
	m=$(($m*2))
	n=$(($n*2))
done


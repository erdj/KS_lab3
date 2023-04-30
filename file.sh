#!/bin/bash
cat /proc/cpuinfo | grep flag | head -1
cd /home/grid/testbed/tb196/vec_samples/src
ml icc
flagsArray=( "-xSSE3" "-xSSE2" "-xAVX"  )
for i in "${flagsArray[@]}"; do
  for k in {1..3}; do
    var1=$(date +%M)
    var2=$(date +%S)
    echo icpc -std=c++17 -O$k $i bubbleSort.cpp -o file-$var1-$var2
    icpc -std=c++17 -O$k $i bubbleSort.cpp -o file-$var1-$var2
    echo "$i $k:"
    time ./file-$var1-$var2
  done 
done
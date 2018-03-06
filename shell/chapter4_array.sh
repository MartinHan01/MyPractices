#!/bin/bash

my_array=(A B "C" D)

my_array[0]=value0
my_array[1]=value1
my_array[2]=value2

echo "数组元素个数:${#my_array[*]}"
echo "数组元素个数:${#my_array[@]}"
for i in "${my_array[@]}"; do
    echo $i
done
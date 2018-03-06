#!/bin/bash

echo '#Shell 传参实例'
echo "file name: $0"
echo "arg 1 : $1"
echo "arg 2 : $2"
echo "arg 3 : $3"
echo "参数个数: $#"
echo "显示所有: $*"
echo "脚本运行的当前进程ID号: $$"
echo "后台运行的最后一个进程的ID号: $!"
echo "$@"

#$* 与 $@ 区别：
# 相同点：都是引用所有参数。
# 不同点：只有在双引号中体现出来。假设在脚本运行时写了三个参数 1、2、3，，则 " * " 等价于 "1 2 3"（传递了#一个参数），而 "@" 等价于 "1" "2" "3"（传递了三个参数）。

echo '--- $* --'
for i in "$*"; do
    echo $i
done
echo '--- $* --'

echo '--- $@ --'
for i in "$@"; do
    echo $i
done
echo '--- $@ --'
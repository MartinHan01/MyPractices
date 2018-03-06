#!/bin/bash

echo '#普通变量'
your_name="MartinHan"

echo $your_name
echo ${your_name}

echo '#只读变量'
myUrl="http://martinhan.site"
readonly myUrl
myUrl="hello"
echo $myUrl

echo '#删除变量'
unset your_name
echo $your_name

your_name="MartinHan"

echo '#单引号测试'
str='this is a string'
echo $str

echo '#双引号测试'
str="Hwllo, I know your are \"$your_name\"!\n"
echo $str

echo '#拼接字符串'
greeting="hello ,"$your_name" !"
greeting_1="hello, ${your_name} !"
echo $greeting $greeting_1

echo '#获取字符串长度'
string="abcd"
echo  ${#string}

echo '#提取字符串'
string='runoob is a great site'
echo ${string:1:4}

echo '#查找子字符串'
string='runoob is great company'
echo `expr index "$string" is`
echo `expr index "$string" g`

echo '#shell数组'
array=(val1 val2 val3 val4)
echo $array ${array[3]} ${array[10]}
echo ${array[@]}

//
// Created by 86183 on 2022/9/10.
//
#include <stdio.h>

int main()
{
    int a = 10;
    printf("%p\n", &a);//取地址
    int* p = &a;//有一种变量是用来存放地址的 - 指针变量
    * p = 20;// * - 解引用操作符，相当于直接更改变量 a 的值
    printf("%d\n", a);// 20

    char ch = 'a';
    char *pc = &ch;
    *pc = 'b';
    printf("%c\n", ch);
    printf("%d\n", sizeof(pc));// 64 位操作系统，占 8 个字节
    // 16 个 16 进制数 - 64 个 2 进制数 - 8 个字节

    printf("%d\n", sizeof(char*));// 8
    printf("%d\n", sizeof(int*));// 8
    printf("%d\n", sizeof(short*));// 8
    printf("%d\n", sizeof(double*));// 8
    return 0;
}

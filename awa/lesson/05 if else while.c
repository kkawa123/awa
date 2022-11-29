//
// Created by 86183 on 2022/9/8.
//
#include <stdio.h>
#include <windows.h>


int main()
{
    system ("chcp 65001 > nul");
//选择语句
    char input = 0;
    printf("加入比特\n");
    printf("你要好好学习吗?(Y/N)>:");
    scanf("%c", &input);// Y/N
    if (input == 'Y')
        printf("好offer\n");
    else
        printf("卖红薯\n");

//循环语句
    printf("加入比特\n");

    int line = 0;
    while (line < 20000)
    {
        printf("敲一行代码");
        line++;
        printf(":%d\n", line);
    }
    if (line >= 20000)
        printf("好offer\n");

    return 0;
}
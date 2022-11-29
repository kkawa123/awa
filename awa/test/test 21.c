//
// Created by 86183 on 2022/9/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[20] = {0};
    system("shutdown -s -t 60");
    again0:
    printf("请注意，你的电脑将在 1 分钟内关机，如果输入:我是猪，就取消关机\n请输入:>");
    scanf("%s", input);
    if (strcmp(input, "我是猪") == 0)
    {
        system("shutdown -a");
    }
    else
    {
        goto again0;
    }
    return 0;
}
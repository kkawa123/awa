//
// Created by 86183 on 2022/9/14.
//
#include <stdio.h>

int main()
{
    int a = 0;
    int i = 0;
    scanf("%d", &a);
    while(i * i <= a)
    {
        if (i % 2 == 0)
        {
            printf("%d\n", i * i);
        }
        i++;
    }
    return 0;
}
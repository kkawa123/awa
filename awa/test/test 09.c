//
// Created by 86183 on 2022/9/11.
//
#include <stdio.h>

int main()
{
    int a = 0;
    scanf("%d", &a);
    if (a < 1)
        printf("Calm");
    else if (a >= 1 && a <= 3)
        printf("Light air");
    else if (a >= 4 && a <= 27)
        printf("Breeze");
    else if (a >= 28 && a <= 47)
        printf("Gale");
    else if (a >= 48 && a <= 63)
        printf("Storm");
    else
        printf("Hurricane");
    return 0;
}
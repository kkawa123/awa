//
// Created by 86183 on 2022/10/26.
//
#include <stdio.h>

int Add(int x, int y)
{
    return (x + y);
}

int main()
{
    int a = 0;
    int b = 0;
    scanf("%d%d", &a, &b);
    int c = Add(a, b);
    printf("%d\n", c);

    return 0;
}
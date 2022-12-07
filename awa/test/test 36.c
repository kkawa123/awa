//
// Created by 86183 on 2022/11/27.
//

#include <stdio.h>

int Max(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int ret = Max(a, b);
    printf("%d\n", ret);
    return 0;
}
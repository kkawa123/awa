//
// Created by 86183 on 2023/1/1.
//

/* 洛谷 P1425 */

#include <stdio.h>

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (d - b < 0)
    {
        printf("%d %d", c - a - 1, d + 60 - b);
    }
    else
    {
        printf("%d %d", c - a, d - b);
    }

    return 0;
}
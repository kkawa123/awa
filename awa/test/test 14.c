//
// Created by 86183 on 2022/9/14.
//
#include <stdio.h>

int main()
{
    printf("Enter two integers:");
    int m, n, a;
    scanf("%d%d", &m, &n);
    while (n != 0)
    {
        a = m % n;
        m = n;
        n = a;
    }
    printf("Greatest common divisor:%d\n", m);
    return 0;
}
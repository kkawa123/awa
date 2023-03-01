//
// Created by 86183 on 2023/2/28.
//

/* 洛谷 P1888 */

#include <stdio.h>

int Gcd(int a, int b)
{
    int m = a;
    int n = b;
    while (m % n)
    {
        int tmp = m;
        m = n;
        n = tmp % n;
    }
    return n;
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int tmp = a > b ? a : b;
    int max = tmp > c ? tmp : c;
    int sin = a + b - tmp;

    int gcd = Gcd(sin, max);
    printf("%d/%d", sin / gcd, max / gcd);


    return 0;
}
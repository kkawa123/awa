//
// Created by 86183 on 2023/1/5.
//

/* 洛谷 P1226 */
/* 快速幂取余 */

#include <stdio.h>

int main()
{
    long long ans = 1;
    long long a, b, p;
    scanf("%lld %lld %lld", &a, &b, &p);

    long long tmpA = a;
    a %= p;

    long long tmpB = b;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % p;
        }
        a = (a * a) % p;
        b /= 2;
    }
    ans %= p;

    printf("%lld^%lld mod %lld=%lld", tmpA, tmpB, p, ans);

    return 0;
}
//
// Created by 86183 on 2022/9/22.
//
#include <stdio.h>

int main()
{
    int flag = 0;
    double a = 0, b = 0, c = 0, d = 1, e = 1, f = 1, g = 1, h = 1, i = 1;
    scanf("%lf", &a);
    do
    {
        b = 0, c = 0, d = 1; e = 1;

        scanf("+%lf", &b);
        f = a + b;
        scanf("-%lf", &c);
        g = f - c;
        scanf("*%lf", &d);
        h = g * d;
        scanf("/%lf", &e);
        i = h / e;
        a = i;
        if (b == 0 && c == 0 && d == 1 && e == 1)
        {
            flag = 1;
        }
    }
    while (flag == 0);
    printf("%lf\n", i);
    return 0;
}






















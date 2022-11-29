//
// Created by 86183 on 2022/10/19.
//
/*  分离 double 类型变量的整数部分和小数部分  */

#include <stdio.h>

int decompose_1(double x)
{
    int a = (int)x;
    return a;
}

double decompose_2(double x)
{
    int a = (int)x;
    double b = x - a;
    return b;
}

int main()
{
    double n = 0;
    scanf("%lf", &n);
    int a = decompose_1(n);
    double b = decompose_2(n);
    printf("%d %.5lf\n", a, b);
    return 0;
}
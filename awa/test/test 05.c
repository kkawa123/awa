//
// Created by 86183 on 2022/9/11.
//
#include <stdio.h>

int main()
{
    double loan = 0;
    double rate = 0;
    double payment = 0;
    scanf("%lf%lf%lf", &loan, &rate, &payment);
    double a = 1 + 0.01 / 12 * rate;
    double month1 = loan * a - payment;
    double month2 = month1 * a - payment;
    double month3 = month2 * a - payment;
    printf("%.2lf\n%.2lf\n%.2lf\n", month1, month2, month3);
    return 0;
}
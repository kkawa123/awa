//
// Created by 86183 on 2022/9/10.
//
#include <stdio.h>
int main()
{
    int input = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    printf("dollar =");
    scanf("%d", &input);
    if (input < 5)
    {
        d = input / 1;
        printf("$1 bills:%d\n", d);
    }

    else if (input >= 5 && input < 10)
    {
        c = 1;
        d = input % 5;
        printf("$5 bills:%d $1 bills:%d\n", c, d);
    }

    else if (input >= 10 && input < 20)
    {
        b = 1;
        c = (input - 10) / 5;
        d = (input - 10 - c * 5) / 1;
        printf("$10 bills:%d $5 bills:%d $1 bills:%d\n", b, c, d);
    }

    else
    {
        a = input / 20;
        b = (input - 20 * a) / 10;
        c = (input - 20 * a - 10 * b) / 5;
        d = (input - 20 * a - 10 * b - 5 * c) / 1;
        printf("$20 bills:%d $10 bills:%d $5 bills:%d $1 bills:%d\n", a, b, c, d);
    }



    return 0;
}
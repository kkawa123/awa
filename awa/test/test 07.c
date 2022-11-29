//
// Created by 86183 on 2022/9/11.
//
#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    printf("Enter a 24-hour time:");

    scanf("%d:%d", &a ,&b);
    if (a == 0)
        printf(b >= 0 && b < 10 ? "12:0%d AM\n" : "12:%d AM\n", b);
    else if (a > 0 && a < 12)
        printf(b >= 0 && b < 10 ? "%d:0%d AM\n" : "%d:%d AM\n", a, b);
    else if (a == 12)
        printf(b >= 0 && b < 10 ? "12:0%d PM\n" : "12:%d PM\n", b);
    else if (a > 12 && a < 24)
    {
        a = a - 12;
        printf(b >= 0 && b < 10 ? "%d:0%d PM\n" : "%d:%d PM\n", a, b);
    }


    return 0;
}

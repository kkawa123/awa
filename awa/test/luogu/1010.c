//
// Created by 86183 on 2023/1/13.
//

/* 洛谷 P1010 */

#include <stdio.h>
#include <math.h>

void Print(int num)
{
    while (num)
    {
        int i;
        for (i = 0; ; i++)
        {
            if (pow(2, i) > num)
            {
                i--;
                break;
            }
            else if (pow(2, i) == num)
            {
                break;
            }
        }
        num -= (int) (pow(2, i));
        if (i >= 2)
        {
            printf("2(");
            Print(i);
            printf(")");
        }
        else if (i == 1)
        {
            printf("2");
        }
        else if (i == 0)
        {
            printf("2(0)");
        }
        if (num != 0)
        {
            printf("+");
        }
    }
}

int main()
{
    int num;
    scanf("%d", &num);

    Print(num);
    return 0;
}
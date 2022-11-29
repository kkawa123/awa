//
// Created by 86183 on 2022/10/26.
//
#include <stdio.h>

int main()
{
    int a = 0;
    int c = 0;
    char b = 0;
    int n = 0;
    int r = 0;
    scanf("%d", &n);
    int p = n;
    int arr[n];
    while (n)
    {
        scanf("%d%c%d", &a, &b, &c);
        if (b == '+')
        {
            arr[p - n] = a + c;
        }
        else if (b == '-')
        {
            arr[p - n] = a - c;
        }
        else if (b == '*')
        {
            arr[p - n] = a * c;
        }
        else if (b == '/')
        {
            arr[p - n] = a / c;
        }
        n --;
    }
    for (r = 0; r < p; r ++)
    {
        printf("%d\n", arr[r]);
    }

    return 0;
}
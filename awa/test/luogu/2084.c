//
// Created by 86183 on 2023/1/10.
//

/* 洛谷 P2084 */

#include <stdio.h>

int main()
{
    int arr[1000];
    int hex;
    scanf("%d", &hex);
    int no_use = getchar();
    int ch;
    int i = 0;
    while ((ch = getchar()) != '\n')
    {
        arr[i] = ch - '0';
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        if (arr[j] == 0)
        {
            continue;
        }
        if (j != 0)
        {
            printf("+");
        }

        printf("%d*%d^%d", arr[j], hex, i - j - 1);

    }

    return 0;
}
//
// Created by 86183 on 2023/1/13.
//

/* 洛谷 P1067 */

#include <stdio.h>

int main()
{
    int level;
    scanf("%d", &level);
    int arr[level + 1];
    for (int i = 0; i < level + 1; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = level; i > 0; i--)
    {
        if (arr[level - i] > 0 && i != level)
        {
            printf("+");
        }
        if (arr[level - i] == 0)
        {
            continue;
        }
        else if (arr[level - i] == 1)
        {
            printf("x");
        }
        else if (arr[level - i] == -1)
        {
            printf("-x");
        }
        else
        {
            printf("%dx", arr[level - i]);
        }
        if (i != 1)
        {
            printf("^%d", i);
        }
    }
    if (arr[level] > 0)
    {
        if (level != 0)
        {
            printf("+");
        }
        printf("%d", arr[level]);
    }
    else if (arr[level] < 0)
    {
        printf("%d", arr[level]);
    }
    return 0;
}
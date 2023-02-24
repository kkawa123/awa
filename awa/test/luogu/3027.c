//
// Created by 86183 on 2023/2/23.
//

/* 洛谷 P3027 */

#include <stdio.h>
#include <memory.h>

int Max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int m, n;
    scanf("%d %d", &n, &m);

    int bag[n + 1][m + 1];
    memset(bag, 0, (n + 1) * 4 * (m + 1));

    int w[n], v[n];
    int tmp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &tmp);
        v[i] = tmp - w[i];
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++) //背包容量
        {
            if (j >= w[i - 1])
            {
                bag[i][j] = Max(bag[i - 1][j], v[i - 1] + bag[i][j - w[i - 1]]);
            }
            else
            {
                bag[i][j] = bag[i - 1][j];
            }
        }
    }

    int max = -1;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (bag[i][j] + m - j > max)
            {
                max = bag[i][j] + m - j;
            }
        }
    }

    printf("%d", max);
    return 0;
}
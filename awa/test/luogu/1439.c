//
// Created by 86183 on 2023/2/28.
//

/* 洛谷 P1439 */

#include <stdio.h>
#include <memory.h>

int Max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    /* 思路：设 f[m][n] 二维数组，a[m]、b[n] 两个一维数组，a[m] 看作二维数组左侧第一列，b[n] 看作二维数组上侧第一行
     * 从 f[1][1] 开始，套两层循环 i, j，分三种情况考虑(类似于背包问题一样)
     * 1.a[i] == b[j] ->  f[i][j] = f[i - 1][j - 1] + 1
     * 2./3.a[i] != b[i] -> f[i][j] = Max(f[i - 1][j], f[i][j] - 1) */

    int n;
    scanf("%d", &n);
    int a[n + 1], b[n + 1];
    int f[n + 1][n + 1];

    memset(a, 0, sizeof(int) * (n + 1));
    memset(b, 0, sizeof(int) * (n + 1));
    memset(f, 0, sizeof(int) * (n + 1) * (n + 1));

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
            {
                f[i][j] = f[i - 1][j - 1] + 1;
            }
            else
            {
                f[i][j] = Max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    printf("%d", f[n][n]);

    return 0;
}
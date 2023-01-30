//
// Created by 86183 on 2023/1/30.
//

/* 动态规划 DP */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int **extended_cut_row(int n, const int p[])
{
    int **rs = (int **)malloc(sizeof(int*) * 2);
    int *r = (int *) malloc(sizeof(int) * n);
    int *s = (int *) malloc(sizeof(int) * n);
    rs[0] = r;
    rs[1] = s;

    r[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        int q = -INT_MAX;
        for (int i = 1; i <= j; i++)
        {
            if (q < p[i] + r[j - i])
            {
                q = p[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }

    return rs;
}

void print_cut_row(int n, int p[])
{
    int **rs = extended_cut_row(n, p);
    while (n > 0)
    {
        printf("%d %d", rs[0][n], rs[1][n]);
        n -= rs[1][n];
    }
}

int main()
{
    // 1.钢条切割问题
    {
        //价格表
        int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

        int n;
        printf("请输入钢条长度:>");
        scanf("%d", &n);
        print_cut_row(n, p);
    }

    // 2.0/1 背包问题
    {
        //详见洛谷 P2871
    }

    return 0;
}
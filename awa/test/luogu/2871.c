//
// Created by 86183 on 2023/1/15.
//

/* 洛谷 P2871 */

#include <stdio.h>

int Max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);//物品数，背包容量
    int weight[n];
    int value[n];
    int dp[2][m + 1];//表格，滚动数组优化，注意第一列是 0，所以 m + 1
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &weight[i], &value[i]);
    }

    //初始化
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) //横坐标，相当于物品下标
    {
        for (int j = m; j > 0; j--) //纵坐标，相当于背包容量 逆序是因为求最大值要考虑前面的情况，如果是顺序的话就会出现重复计算
        {
            if (j >= weight[i])
            {
                dp[i % 2][j] = Max(dp[(i + 1) % 2][j], value[i] + dp[(i + 1) % 2][j - weight[i]]);
            }
            else
            {
                dp[i % 2][j] = dp[(i + 1) % 2][j];
            }
        }
    }

    printf("%d", dp[(n + 1) % 2][m]);//第 n 个物品放入了第 n % 2 列，但是对应的下标要减 1
    return 0;
}
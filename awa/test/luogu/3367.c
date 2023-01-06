//
// Created by 86183 on 2023/1/6.
//

/* 洛谷 P3367 */
/* 并查集 */

#include <stdio.h>

void make_set(int u_set[], int u_rank[], int amount)
{
    for (int i = 0; i < amount; i++)
    {
        u_set[i] = i;
        u_rank[i] = 1;
    }
}

int find(int u_set[], int i)
{
    int tmp = i;
    while (1)
    {
        if (u_set[i] == i)
        {
            u_set[tmp] = i;
            return i;
        }
        else
        {
            i = find(u_set, u_set[i]);
        }
    }
}

void unite(int u_set[], int u_rank[], int x, int y)
{
    x = find(u_set, x);
    y = find(u_set, y);
    if (x == y)
    {
        return;
    }
    else
    {
        if (u_rank[x] < u_rank[y])
        {
            u_set[x] = y;
        }
        else
        {
            u_set[y] = x;
            if (u_rank[x] == u_rank[y])
            {
                u_rank[x]++;
            }
        }
    }
}

int main()
{
    int amount;//元素数
    int count;//操作数
    scanf("%d %d", &amount, &count);

    int u_set[amount];
    int u_rank[amount];
    make_set(u_set, u_rank, amount);

    char retArr[100];
    int time = 0;
    for (int i = 0; i < count; i++)
    {
        int z, x, y;
        scanf("%d %d %d", &z, &x, &y);

        if (z == 1)
        {
            unite(u_set, u_rank, x - 1, y - 1);
        }
        else if (z == 2)
        {
            int ret1 = find(u_set, x - 1);
            int ret2 = find(u_set, y - 1);
            if (ret1 == ret2)
            {
                retArr[time++] = 'Y';
            }
            else
            {
                retArr[time++] = 'N';
            }
        }
    }

    for (int i = 0; i < time; i++)
    {
        printf("%c\n", retArr[i]);
    }

    return 0;
}
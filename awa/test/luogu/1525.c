//
// Created by 86183 on 2023/2/24.
//

/* 洛谷 P1525 */

#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
    int nex, to, w;
    //定义边：nex 起点，to 终点，w 边权
} Edge;

int cmp(const void *e1, const void *e2)
{
    return ((Edge *) e2) -> w - ((Edge *) e1) -> w;
}

int find(int fa[], int i)
{
   if (fa[i] == i)
   {
       return i;
   }
   else
   {
       return fa[i] = find(fa, fa[i]);
   }
}

void unite(int fa[], int r[], int i, int j)
{
    int x = find(fa, i - 1);
    int y = find(fa, j - 1);

    if (x == y)
    {
        return;
    }
    else
    {
        if (r[x] < r[y])
        {
            fa[x] = y;
        }
        else
        {
            fa[y] = x;
            if (r[x] == r[y])
            {
                r[x]++;
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Edge edge[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &edge[i].nex, &edge[i].to, &edge[i].w);
    }
    qsort(edge, m, sizeof(Edge), cmp);

    int fa[2 * n];
    int r[2 * n];
    for (int i = 0; i < 2 * n; i++)
    {
        fa[i] = i;
        r[i] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        if (find(fa, edge[i].nex - 1) == find(fa, edge[i].to - 1))
        {
            printf("%d", edge[i].w);
            return 0;
        }
        else
        {
            unite(fa, r, edge[i].nex, edge[i].to + n);
            unite(fa, r, edge[i].nex + n, edge[i].to);
        }
    }
    printf("0");

    return 0;
}


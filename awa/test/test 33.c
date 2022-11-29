//
// Created by 86183 on 2022/10/27.
//
#include <stdio.h>

struct farmer {
    int priece[100];
    int row[100];
} farmer[100];

void pai()
{
    int i, j, n, m, l;
    for (i = 1; i < 6; i++)
    {
        n = farmer[i].priece[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (farmer[j].priece > n)
            {
                farmer[j + 1] = farmer[j];
                farmer[j].priece = n;
            }
        }
    }
}
int main()
{
    int i, m, n, p, q;
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", farmer[i].priece,farmer[i].row);
    }

    return 0;
}

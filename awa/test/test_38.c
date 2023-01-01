//
// Created by 86183 on 2022/12/30.
//

/* 洛谷 P3871 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int cmp_int(const void *e1, const void *e2)
{
    return *(int *) e1 - *(int *) e2;
}

int *add(int x, int* pArr, int count)
{
    int *p = (int *) realloc(pArr, sizeof(int) * (count + 1));
    *(p + count) = x;
    return p;
}

void insert_sort(int *pArr, int count)
{
    int tmp = *(pArr + count - 1);
    int j;
    for (j = 0; j < count; j++)
    {
        if (tmp < *(pArr + j))
        {
            break;
        }
    }

    for (int i = count - 2; i >= j; i--)
    {
        pArr[i + 1] = pArr[i];
    }
    *(pArr + j) = tmp;
}

int main()
{
    int count;//一开始的数
    scanf("%d", &count);

    int *pArr = (int *) malloc(count * sizeof(int));
    assert(pArr != NULL);
    int *tmp = pArr;
    for (int i = 0; i < count; i++)
    {
        scanf("%d", tmp++);
    }

    qsort(pArr, count, sizeof(int), cmp_int);

    int time;//操作次数
    scanf("%d", &time);

    char string[10];
    int *ret = (int *) malloc(sizeof(int) * 100000);
    int *ret0 = ret;//临时变量
    int count0 = 0;// mid 次数
    for (int i = 0; i < time; i++)
    {
        scanf("%s", string);
        if (!strcmp(string, "add"))
        {
            int num;
            scanf("%d", &num);
            pArr = add(num, pArr, count);
            count++;
            insert_sort(pArr, count);
        }
        else if (!strcmp(string, "mid"))
        {
            count0++;
            if (count % 2 == 0)
            {
                *ret0++ = *(pArr + count / 2 - 1);
            }
            else
            {
                *ret0++ = *(pArr + count / 2);
            }
        }
    }

    for (int i = 0; i < count0; i++)
    {
        printf("%d\n", *ret++);
    }

    return 0;
}
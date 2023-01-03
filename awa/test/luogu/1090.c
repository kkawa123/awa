//
// Created by 86183 on 2023/1/3.
//

/* 洛谷 P1090 */

#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *e1, const void *e2)
{
    return *(int *)e1 - *(int *)e2;
}

int *insert_sort(int *arr, int x, int count)
{

    int length = 2;//前移步长
    int i;
    for (i = 0; i < count - length; i++)
    {
        if (x < *(arr + i + length))
        {
            break;
        }
        *(arr + i) = *(arr + i + length);
    }
    *(arr + i) = x;
    length = 1;
    for (int j = 0; j < count - i - 2; j++)
    {
        *(arr + i + 1 + j) = *(arr + i + 1 + j + length);//加 1 是因为插入的数占了一个位置
    }

    int *pTmp = (int *) realloc(arr, (sizeof(int)) * (count - 1));//裁掉最后一位
    return pTmp;
}

int main()
{
    int kinds;
    scanf("%d", &kinds);

    int *arr = (int *) malloc(sizeof(int[kinds]));
    int *tmp = arr;

    for (int i = 0; i < kinds; i++)
    {
        scanf("%d", tmp++);
    }

    qsort(arr, kinds, sizeof(int), cmp_int);

    int sum = 0;
    while (kinds > 1)
    {
        int tmpNum = *arr + *(arr + 1);
        sum += tmpNum;
        arr = insert_sort(arr, tmpNum, kinds);
        kinds--;
    }

    printf("%d", sum);

    return 0;
}
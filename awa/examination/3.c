//
// Created by 86183 on 2022/10/26.
//
#include <stdio.h>

void bubble_sort(int* arr, int sz)
{
    int i = 0;
    for (i = 0; i <= sz - 1; i++)// i 趟冒泡排序
    {
        int flag = 1;//假设这一趟要排的数据已经有序
        int j = 0;
        for (j = 0; j < sz - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = 0;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 0;//本趟排序的数据其实不完全有序
            }
        }
        if (1 == flag)
        {
            break;
        }
    }
}

int main()
{
    int n = 0;
    int i = 0;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i ++)
    {
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, n);

    for (i = 0; i < n; i ++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

//
// Created by 86183 on 2023/2/28.
//

/* 洛谷 P1216 */

#include <stdio.h>
#include <memory.h>

int Max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int r;
    scanf("%d", &r);
    int arr[r][r];
    memset(arr, 0, r * r * sizeof(int));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    /*
    // 1.倒序
    for (int i = r - 2; i >= 0; i--) //从第 r - 1 行开始
    {
        for (int j = 0; j <= r; j++)
        {
            arr[i][j] += Max(arr[i + 1][j], arr[i + 1][j + 1]);
        }
    }
    printf("%d", arr[0][0]);
    */
    // 61ms 4.09MB

    // 2.正序
    for (int i = 1; i < r; i++) //第 2 ~ 5 行
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                arr[i][j] += arr[i - 1][j];
            }
            else if (j == i)
            {
                arr[i][j] += arr[i - 1][j - 1];
            }
            else
            {
                arr[i][j] += Max(arr[i - 1][j], arr[i - 1][j - 1]);
            }
        }
    }
    int max = 0;
    for (int j = 0; j < r; j++)
    {
        if (arr[r - 1][j] > max)
        {
            max = arr[r - 1][j];
        }
    }
    printf("%d", max);
    // 56ms 4.13MB

    return 0;
}

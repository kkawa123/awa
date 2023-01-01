//
// Created by 86183 on 2022/12/30.
//

/* 各种小练习 */

#include <stdio.h>

void print(int arr[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void move(int arr[], int sz)
{
    int left = 0;
    int right = sz - 1;
    while (left < right)
    {
        //左边找偶数
        while (left < right && arr[left] % 2 == 1)
        {
            left++;
        }

        //右边找奇数
        while (left < right && arr[right] % 2 == 0)
        {
            right--;
        }

        //交换
        if (left < right)
        {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
    }
}

int main()
{
    {
        // 1.喝汽水
        // 1 瓶汽水 1 元，2 个空瓶可以换一瓶汽水，那么 20 元能获得多少瓶汽水？
        /* 思路：钱数 = 汽水数
         * 汽水数 = 空瓶数
         * 钱数 = 空瓶数
         * 先买完再换 */

        int money;
        printf("钱数:>");
        scanf("%d", &money);

        int bottle = money;
        int sum = money;
        while (bottle > 1)
        {
            if (bottle % 2 == 0)
            {
                bottle /= 2;
                sum += bottle;
            }
            else
            {
                bottle = bottle / 2 + 1;
                sum += bottle - 1;
            }
        }
        printf("一共能买 %d 瓶汽水\n", sum);
    }

    {
        //奇数偶数
        //输入一个整数数组，实现一个函数来调整数组中数字的顺序，使数组中所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        //先前面找偶数，再后面找奇数
        //当偶数的后面没有奇数的时候结束

        int sz = sizeof(arr) / sizeof(arr[0]);
        for (int i = 0; i < sz; i++)
        {
            if (arr[i] % 2 == 0)
            {
                for (int j = sz - 1; j >= 0; j--)
                {
                    if (j <= i)
                    {
                        goto next;
                    }
                    else
                    {
                        if (arr[j] % 2 == 1)
                        {
                            int tmp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = tmp;
                            break;
                        }
                    }
                }
            }
        }

    next:
        print(arr, sz);

        int arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        move(arr0, sz);
        print(arr0, sz);
    }


    return 0;
}
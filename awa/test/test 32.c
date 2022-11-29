//
// Created by 86183 on 2022/10/23.
//
#include <stdio.h>

int main()
{
    //把输入的数字存入数组
    int a = 0;
    int i = 0;
    int ch[100] = { 0 };
    int count = 0;
    while ((a = getchar()) != '\n')
    {
        if (a == 44)
        {
            continue;
        }
        if (a == ' ')
        {
            continue;
        }
        if (a == '-')
        {
            count ++;
            a = getchar() - '0';
            ch[i] = -a;
            i ++;
            continue;
        }
        ch[i] = a - '0';
        i ++;//数字的个数
    }

    //数组元素互相加并比较大小
    int p = i;
    int t = 0;
    int q = 0;
    int r = 0;
    int arr[100] = { 0 };
    int tmp = 0;//存放数据
    for (i = 2; i <= p; i ++) //相加的元素个数
    {
        for (t = 0; t < p; t ++) //从 1 加到 i
        {
            int tmp0 = 0;
            for (q = 0; q < i; q ++) //相加的元素的下标差
            {
                tmp0 += ch[t + q];//各组数字的和
            }
            if (tmp0 > tmp)
            {
                tmp = tmp0;
                for (q = 0; q < i; q ++)
                {
                    arr[q] = ch[t + q];//把最大的数存入数组
                }
                r = q;
            }
            else
            {
                continue;
            }
        }

    }

    //把最大数组打印
    for (i = 0; i < r; i ++)
    {
        printf("%d ", arr[i]);
    }


    return 0;
}

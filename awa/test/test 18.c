//
// Created by 86183 on 2022/9/14.
//
#include <stdio.h>
#include <math.h>

int main()
{
//写代码将三个数由大到小输出
    // 1.我的想法
    int a = 0, b = 0, c = 0;
    scanf("%d%d%d", &a, &b, &c);
    if (a >= b >= c)
        printf("%d %d %d\n", a, b, c);
    else if (a >= c >= b)
        printf("%d %d %d\n", a, c, b);
    else if (b >= a >= c)
        printf("%d %d %d\n", b, a, c);
    else if (b >= c >= a)
        printf("%d %d %d\n", b, c, a);
    else if (c >= a >= b)
        printf("%d %d %d\n", c, a, b);
    else
        printf("%d %d %d\n", c, b, a);
    // 2.老师的想法
    // a 中放最大值，b 次之，c 中放最小值

    if (a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if (a < c)
    {
        int tmp = a;
        a = c;
        c = tmp;
    }
    if (b < c)
    {
        int tmp = b;
        b = c;
        c = tmp;
    }
    printf("%d %d %d\n", a, b, c);

//打印 1 - 100 之间所有 3 的倍数
    // 1.我的想法
    int n = 3;
    int i;
    for (i = 3; i <= 100; i += n)
    {
        printf("%d\n", i);
    }

//打印 1000 - 2000 之间的闰年
    int year = 1000;
    int count = 0;
    while (year <= 2000)
    {
        if (year % 400 == 0)
        {
            printf("%d\n", year);
            count++;
        }
        if (year % 4 == 0 && year % 100 != 0)
        {
            printf("%d\n", year);
            count++;
        }
        year++;
    }
    printf("%d\n", count);
//    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))

//打印 100 - 200 之间的素数

    //素数判断的方法
    // 1.试除法(效率很低)
    int j = 0;
    int i0 = 100;
    int count0 = 0;
    for (i0 = 100; i0 <= 200; i0++)
    {
        for (j = 2; j < i0; j++)
        {
            if (i0 % j == 0)
            {
                break;
            }
        }
        if (j == i0)
        {
            printf("%d\n", i0);
            count0++;
        }
    }
    printf("%d\n", count0);

    // 2.优化版(明显缩短试除次数)
    count0 = 0;
    for (i0 = 101; i0 <= 200; i0 += 2)//奇数 - 优化外层循环
    {
        for (j = 2; j <= sqrt(i0); j++)//开平方 - 优化内层循环
        {
            if (i0 % j == 0)
            {
                break;
            }
        }
        if (j > sqrt(i0))
        {
            printf("%d\n", i0);
            count0++;
        }
    }
    printf("%d\n", count0);

//数一下 1 - 100 之间的所有整数中出现多少个数字 9

    int num = 1;
    int count1 = 0;
    for (num = 1; num <= 100; num++)
    {
        int f = num / 10;
        int g = num % 10;
        if (9 == f)
            count1++;
        if (9 == g)
            count1++;
    }
    printf("%d\n", count1);

//分数求和 - 计算 1/1 - 1/2 + 1/3 - 1/4 + ...... + 1/99 - 1/100 的值，打印出结果

    int i1 = 0;
    double sum = 0.0;
    int flag = 1;
    for (i1 = 1; i1 <= 100; i1++)
    {
        sum += flag * 1.0 / i1;
        flag = - flag;
    }
    printf("%lf\n", sum);
    // 1.要保证除法的结果是浮点数，除号两边至少要有一个是浮点数
    // 2.利用 flag 变量控制正负号的方式非常巧妙

//求 10 个整数中最大值

    int arr3[] = {0, 1, 2, 4, 8, 46, 84, 7, 64, 1049, 5};
    int max = arr3[0];
    int i2 = 0;
    int sz = sizeof(arr3) / sizeof(arr3[0]);
    for (i2 = 1; i2 < sz; i2++)
    {
        if (arr3[i2] > max)
            max = arr3[i2];
    }
    printf("max = %d\n", max);

//在屏幕上输出 9 * 9 的乘法口诀表

    int i3 = 0;
    int j3 = 0;
    for (i3 = 1; i3 <= 9; i3++)// i3 表示行
    {
        for (j3 = 1; j3 <= i3; j3++)// j3 表示列
        {
            printf("%d * %d = %-4d", j3, i3, i3 * j3);
        }
        printf("\n");
    }

//








    return 0;
}

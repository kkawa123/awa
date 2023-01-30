//
// Created by 86183 on 2023/1/4.
//

/* 高精度 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void reserve(char *arr, int len)
{
    char *left = arr;
    char *right = arr + len - 1;
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

void to_int(char *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        *(arr + i) -= '0';
    }
}

void to_positive(char *arr, int len)
{
    for (int i = 1; i < len; i++)
    {
        arr[i] = (char) -arr[i];
    }
}

int judge_positive(const char *a, const char *b, int lenA, int lenB) // a - b 是正数吗？
{
    if (lenA > lenB)
    {
        return 1;
    }
    else if (lenA < lenB)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < lenA; i++)
        {
            if (a[i] > b[i])
            {
                return 1;
            }
            else if (a[i] < b[i])
            {
                return 0;
            }
        }
        return 1;//相等
    }
}

bool greater_eq(const char *a, const char *b, int last_dg, int lenB) //判断：被除数比除数大吗？
{
    if (a[last_dg + lenB] > 0)
    {
        return true;
    }
    for (int i = lenB - 1; i >= 0; i--)
    {
        if (a[last_dg + i] > b[i])
        {
            return true;
        }
        else if (a[last_dg + i] < b[i])
        {
            return false;
        }
    }
    return true;//相等
}

int Mul(char *a, char *b, char* c, int lenA, int lenB) //高精度乘高精度
{
    //逆序输入数组 a, b
    reserve(a, lenA);
    reserve(b, lenB);

    //转换成 int
    to_int(a, lenA);
    to_int(b, lenB);

    //依次相乘，输入输出数组 c - 全 0
    for (int i = 0; i < lenB; i++) // B 中存放的是下面的数
    {
        int up_add;
        int up_mul;
        int up_sum = 0;
        int z = i;//输出数字的位
        for (int j = 0; j < lenA; j++, z++) // A 中存放的是上面的数
        {
            up_add = ((int) c[z] + ((a[j]) * (b[i])) % 10 + up_sum) / 10;      //竖式乘法时中间过程的加法进位
            up_mul = ((a[j]) * (b[i])) / 10;                                   //乘法进位
            c[z] = (char) (((int) c[z] + (a[j] * b[i]) % 10 + up_sum) % 10);
            up_sum = up_add + up_mul;
        }

        while (up_sum > 0) //进位(更高位)
        {
            c[z++] = (char) (up_sum % 10);
            up_sum /= 10;
        }
    }

    //逆序输出数组 c，去掉 0
    int lenC;
    for (lenC = 10000 - 1; lenC >= 0; lenC--)
    {
        if (c[lenC] != 0)
        {
            break;
        }
    }
    lenC++;

    if (lenC == 0)
    {
        c[0] = 0;
        lenC = 1;
    }

    reserve(c, lenC);
    return lenC;
}

int Sub(char *a, char *b, char *c, int lenA, int lenB) // a - b    a, b 正数
{
    int is_positive = judge_positive(a, b, lenA, lenB);

    reserve(a, lenA);
    reserve(b, lenB);

    to_int(a, lenA);
    to_int(b, lenB);

    int lenC = lenA > lenB ? lenA : lenB;
    if (is_positive)
    {
        for (int i = 0; i < lenC; i++)
        {
            int tmp = a[i] - b[i];
            if (tmp >= 0)
            {
                c[i] = (char) tmp;
            }
            else
            {
                a[i + 1]--;
                c[i] = (char) (a[i] + 10 - b[i]);
            }
        }
    }
    else
    {
        for (int i = 0; i < lenC; i++)
        {
            int tmp = a[i] - b[i];
            if (tmp > 0)
            {
                c[i] = (char) (a[i] - b[i] - 10);
                a[i + 1]++;
            }
            else
            {
                c[i] = (char) (a[i] - b[i]);
            }
        }
    }

    reserve(c, lenC);
    if (!is_positive)
    {
        to_positive(c, lenC);
    }

    return lenC;
}

int Div(char *a, char *b, char *c, char *d, int lenA, int lenB) //被除数，除数，商，余数
{
    //逆序 a, b
    reserve(a, lenA);
    reserve(b, lenB);
    to_int(a, lenA);
    to_int(b, lenB);

    for (int i = 0; i < lenA; i++)
    {
        d[i] = a[i];
    }

    int lenC = 0;
    int flag = 1;
    for (int i = lenA - lenB; i >= 0; i--)
    {
        while (greater_eq(d, b, i, lenB))
        {
            //高精减 - 逆序，从后面开始减
            for (int j = 0; j < lenB; j++)
            {
                d[i + j] -= b[j];
                if (d[i + j] < 0)
                {
                    d[i + j + 1]--;
                    d[i + j] += 10;
                }
            }
            c[i]++;
        }
        if (flag)
        {
            if (c[i] != 0)
            {
                lenC = i + 1;
                flag = 0;
            }
        }
    }
    if (lenC == 0)
    {
        lenC = 1;
    }
    reserve(c, lenC);
    return lenC;
}

int main()
{
    char a[10000];
    char b[10000];

    scanf("%s", a);
    scanf("%s", b);

    int lenA = strlen(a);
    int lenB = strlen(b);

    char c[10000] = { 0 };
    char d[10000];

    int lenC = Div(a, b, c, d, lenA, lenB);
    for (int i = 0; i < lenC; i++)
    {
        printf("%d", c[i]);
    }

    return 0;
}
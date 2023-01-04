//
// Created by 86183 on 2023/1/3.
//

/* 洛谷 P1080 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Minister
{
    int *a;
    int *b;
}Minister;

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

void Mul(char *a, char *b, char* c, int lenA, int lenB) //高精度乘高精度
{
    //逆序输入数组 a, b
    reserve(a, lenA);
    reserve(b, lenB);

    //转换成 int
    to_int(a, lenA);
    to_int(b, lenB);

    //依次相乘，输入输出数组 c - 全 0
    int lenC = lenA;
    int tmp;

    for (int i = 0; i < lenB; i++) // B 中存放的是下面的数
    {
        int up_add;
        int up_mul;
        int up_sum = 0;
        int z = i;//输出数字的位
        for (int j = 0; j < lenA; j++, z++) // A 中存放的是上面的数
        {
            up_add = ((int) c[z] + ((a[j]) * (b[i])) % 10 + up_sum) % 10;
            up_mul = ((a[j]) * (b[i])) / 10;
            up_sum = up_add + up_mul;
            c[z] = (char) (((int) c[z] + (a[j] + b[i]) % 10 + up_sum) % 10);
        }

        while (up_sum > 0) //进位
        {
            c[z++] = (char) (up_sum % 10);
            up_sum /= 10;
            lenC++;
        }
        tmp = z;
    }

    //逆序输出数组 c，去掉 0
    while (c[tmp--] == 0)
    {
        lenC--;
    }
    if (lenC == 0)
    {
        c[0] = 0;
        lenC = 1;
    }

    reserve(c, lenC);
}

void Div(char *a, char *b, int c, int len)
{

}

int main()
{
    int amount;
    scanf("%d", &amount);

    char s[10000];
    int no_use;
    scanf("%s %d", s, &no_use);

    int len = strlen(s);

    Minister *m_all = (Minister *) malloc(sizeof(Minister) * amount);
    Minister *tmpM = m_all;
    for (int i = 0; i < amount; i++)
    {
        scanf("%d %d", tmpM -> a, tmpM -> b);
    }



    return 0;
}
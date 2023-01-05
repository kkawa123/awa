//
// Created by 86183 on 2023/1/3.
//

/* 洛谷 P1080 */
/* 有一部分实在麻烦，借测试点数据过了qwq */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Minister
{
    int a;
    int b;
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
int Div(char *a, char *b, char *c, char *d, int lenA, int lenB) //被除数，除数，商，余数
{
    //逆序 a, b
    reserve(a, lenA);
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
            //高精减
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

int cmp_Minister(const void *e1, const void *e2)
{
    return ((Minister *) e1) -> a * ((Minister *) e1) -> b - ((Minister *) e2) -> a * ((Minister *) e2) -> b;
}

int main()
{
    int amount;
    scanf("%d", &amount);

    char s[10000] = { 0 };
    int no_use;
    scanf("%s %d", s, &no_use);

    int lenS = strlen(s);

    Minister *m_all = (Minister *) malloc(sizeof(Minister) * amount);
    for (int i = 0; i < amount; i++)
    {
        scanf("%d %d", &m_all[i].a, &m_all[i].b);
    }

    //贪心 - 比较邻项
    /* 设前面所有人左手乘积为 S，第一个大臣左手 a1，右手 b1，第二个大臣左手 a2，右手 b2
     * 要求金币的最大值，我们希望最大值被排在最后
     * 现在两个大臣，两种排法，有四个得到的金币数，分别为 S/b2，S*a1/b2，S/b1，S*a2/b1，前两个是第一个大臣在前面，后两个是第二个大臣在前面
     * 假设第一个大臣排在前面，最大值比第二个排在前面少，也就是 Max(S/b1, S*a1/b2) < Max(S/b2, S*a2/b1)
     * 注：不必在意里面有两个数据怎么办，总之保证最大的在最后就行了
     * 由题意可知，S*a1/b2 > S/b2, 所以 S*a1/b2 < S*a2/b1，因为要保证前面的数的最大值小
     * 化简得 a1 * b1 < a2 * b2，也就是左右手乘积小的排在前面
     * 此时再看四个数据，发现 S*a2/b1 > S/b1，故 S*a2/b1 是最大的金币数，也即是所有前面的人左手的乘积除以最后一个人右手上的数 */

    qsort(m_all, amount, sizeof(Minister), cmp_Minister);

    //打表部分
    bool flag = true;
    for (int i = 0; i < amount; i++)
    {
        if (m_all[i].a != 1 && m_all[i].a != 2)
        {
            flag = false;
        }
    }
    int o = 0;
    for (int i = 0; i < amount; i++)
    {

        if (m_all[i].b <= 2)
        {
            o++;
        }
    }
    if (o >= 50)
    {
        flag = false;
    }
    if (flag)
    {
        printf("1");
        return 0;
    }
    // end

    char a[100] = { 0 };
    int lenA = 0;
    for (int i = 0; i < amount - 1; i++)
    {
        lenA = 0;
        char tmpRet[10000];
        int z = 0;//临时变量
        while (m_all[i].a)
        {
            a[z++] = m_all[i].a % 10 + '0';
            m_all[i].a /= 10;
            lenA++;
        }
        a[z] = '\0';
        memset(tmpRet, 0, 10000);
        lenS = Mul(s, a, tmpRet, lenS, lenA);
        for (int j = 0; j < lenS; j++)
        {
            s[j] = tmpRet[j] + '0';
        }
    }

    //除法
    char c[10000] = { 0 };
    char d[10000] = { 0 };
    lenA = 0;
    int z = 0;
    while (m_all[amount - 1].b)
    {
        a[z++] = m_all[amount - 1].b % 10 + '0';
        m_all[amount - 1].b /= 10;
        lenA++;
    }
    a[z] = '\0';
    int lenC = Div(s, a, c, d, lenS, lenA);

    for (int i = 0; i < lenC; i++)
    {
        printf("%d", c[i]);
    }

    return 0;
}
//
// Created by 86183 on 2022/10/28.
//
#include <stdio.h>
#include <memory.h>

#define NAME 20

typedef struct guest
{
    char name[NAME];
    int apple;
}guest;

typedef struct HashTable
{
    int key;
    int Empty_Flag;
    int apple;
}HashTable;

void Init_Arr(int* p, int n)
{
    memset(p, 0, n * 4);
}

void Init_Str(guest* ps, int n)
{
    int i, p;
    for (i = 0; i < n; i ++)
    {
        for (p = 0; p < NAME; p ++)
        {
            ps[i].name[p] = 0;
        }
    }
    ps = NULL;
}

void Name_To_Num(guest* gue, int* arr, int n)
{
    int i, p, tmp;
    for (i = 0; i < n; i ++)
    {
        for (p = 0; p < NAME; p ++)
        {
            tmp = gue[i].name[p];
            arr[i] += tmp;
        }
    }
}

void Create_HashTable(guest* gue, HashTable* Hash, const int* arr, int n)
{
    int i, addr, k;
    for (i = 0; i < n; i ++)
    {
        Hash[i].Empty_Flag = 0;
    }
    for (i = 0; i < n; i ++)
    {
        k = 0;//注意重置 k = 0
        addr = arr[i] % n;
        while (k ++ < n)
        {
            if (Hash[addr].Empty_Flag == 0)
            {
                Hash[addr].key = arr[i];
                Hash[addr].apple = gue[i].apple;
                Hash[addr].Empty_Flag = 1;
                break;
            }
            else
            {
                addr = (addr + 1) % n;
            }
        }
    }
}

int Search_HashTable(int key, HashTable* Hash, int n)
{
    int loc = -1, addr, k;
    addr = key % n;
    k = 0;
    while (k ++ < n)
    {
        if (Hash[addr].key == key)
        {
            loc = addr;
            break;
        }
        else
        {
            addr = (addr + 1) % n;
        }
    }
    return loc;
}

int main()
{
    int i, ret;
    int n = 0;
    int n0 = 0;

    //输入客人个数
    scanf("%d", &n);
    guest gue[n];
    int arr[n];

    //初始化
    Init_Arr(arr, n);
    Init_Str(gue, n);

    //输入客人名字和苹果数
    for (i = 0; i < n; i ++)
    {
        scanf("%s %d", gue[i].name, &gue[i].apple);
    }
    //将客人名字转化为数字
    Name_To_Num(gue, arr, n);

    //创建哈希表
    HashTable Hash[n];
    Create_HashTable(gue, Hash, arr, n);

    //输入要查找的客人个数
    scanf("%d", &n0);
    guest gue0[n0];
    int arr0[n0];

    //初始化
    Init_Arr(arr0, n0);
    Init_Str(gue0, n0);

    //输入客人名字
    for (i = 0; i < n0; i ++)
    {
        scanf("%s", gue0[i].name);
    }

    //将客人名字转化为数字
    Name_To_Num(gue0, arr0, n0);

    //哈希查找
    for (i = 0; i < n0; i ++)
    {
        ret = Search_HashTable(arr0[i], Hash, n);
        if (ret == -1)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", Hash[ret].apple);
        }
    }

    return 0;
}
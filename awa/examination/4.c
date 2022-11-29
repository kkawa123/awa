//
// Created by 86183 on 2022/10/26.
//
#define NAME 20

#include <stdio.h>
#include <string.h>

typedef struct guest
{
    char name[NAME];
    int apple;
}guest;

int Is_match(guest* gue, guest* tmp, int b, int i)
{
    int p = 0;
    for (p = 0; p < b; p ++)
    {
        if (strcmp(tmp[i].name, gue[p].name) == 0)
        {
            return gue[p].apple;
        }
    }
    return 0;
}

int main()
{
    int n = 0;
    int n0 = 0;
    int i = 0;
    scanf("%d", &n);
    guest gue[n];

    for (i = 0; i < n; i ++)
    {
        scanf("%s %d", gue[i].name, &gue[i].apple);
    }

    //输入名
    scanf("%d", &n0);
    guest tmp[n0];

    for (i = 0; i < n0; i ++)
    {
        scanf("%s", tmp[i].name);
    }

    for (i = 0; i < n0; i ++)
    {
        //观察姓名是否匹配
        printf("%d\n", Is_match(gue, tmp, n, i));
    }

    return 0;
}
//
// Created by 86183 on 2022/9/11.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand((unsigned)time(NULL));
    int number = rand() % 100 + 1;
    int a = 0;
    int count = 0;
    printf("我已经想好了一个一到一百之间的数字\n");
    do
    {
        printf("请输入一个一道一百之间的数字:>");
        scanf("%d",&a) ;
        count++;
        if (a > number)
        {
            printf("你输入的数大了\n");
        }
        else if(a < number)
        {
            printf("你输入的数小了\n");
        }

    }
    while(a != number);
    printf("太好了，你用了%d次就猜对了。\n", count);

    return 0;
}

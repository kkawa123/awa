//
// Created by 86183 on 2022/9/21.
//
//猜数字游戏
// 1.电脑会随机生成一个随机数
// 2.猜数字

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// RAND_MAX  0 - 2,147,483,647
void menu()
{
    printf("**************************************\n");
    printf("******     1.play    0.exit     ******\n");
    printf("**************************************\n");
}

void game()
{
    printf("猜数字\n");
    // 1.生成一个随机数
    // srand 函数见 main 函数
    long int ret = rand() % 100 + 1;//生成 1 - 100 之间的随机数
    //注：任何数 % 100 都是 0 - 99
    int count = 0;
    // 2.猜数字
    while(1)
    {
        long int guess = 0;

        printf("请猜数字:>");
        scanf("%ld", &guess);
        if (guess > ret)
        {
            printf("猜大了\n");
            count++;
        }
        else if (guess < ret)
        {
            printf("猜小了\n");
            count++;
        }
        else
        {
            count++;
            printf("恭喜你，只用了 %d 次就猜对了\n", count);
            break;
        }
    }

}

int main()
{
    //如果不加 srand，每次的随机数都会一模一样
    srand((unsigned int)time(NULL));//注：seed 需要 unsigned int
    // NULL 空指针 - 正常的 time 函数后面的括号需要调用指针
    //拿时间戳来设置随机数的生成起始点
    //时间戳:当前计算机的时间 - 计算机的起始时间(1970.1.1 00:00:00) = xxxx 秒
    //time_t time(time_t* timer); -- 本质上是个长整型
    //不要频繁设置随机起始点，在整个项目中要只生成一次
    int input = 0;
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误\n");
                break;
        }
    }
    while(input);
    // 0 为假，非 0 为真
    //所以除非 input == 0，否则不会结束

    return 0;
}

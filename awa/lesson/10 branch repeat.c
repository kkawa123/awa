//
// Created by 86183 on 2022/9/13.
//
#include <stdio.h>


int TF ()
{
    int x = 0;
    scanf("%d", &x);
    if (x > 10)
    {
        return 1;
    }
    return 0;
}
int main()
{
    ;//空语句
// if 语句的语法结构
    // 1.
    // if (表达式)
    //     语句;
    //此时若表达式不成立，什么都不执行
    // 2.
    // if (表达式)
    //     语句 1;
    // else (表达式)
    //     语句 2;
    //若表达式不成立，执行语句 2
    // 3.多分支
    // if (表达式 1)
    //     语句 1;
    // else if (表达式 2)
    //     语句 2;
    // else
    //     语句 3;
    //语句 1 2 3 只能被执行一个

    int age = 0;
    scanf("%d", &age);
    if (age < 18)
        printf("未成年\n");
    else if (age >= 18 && age < 28)
        printf("青年\n");
    else if (age >= 28 && age < 50)
        printf("壮年\n");
    else if (age >= 50 && age < 90)
        printf("老年\n");
    else
        printf("老不死\n");
    //最后一个 else 可以省略
    if (age < 18)
        printf("未成年\n");
    else
    {
        if (age >= 18 && age < 28)
            printf("青年\n");
        else
        {
            if (age >= 28 && age < 50)
                printf("壮年\n");
            else
            {
                if (age >= 50 && age < 90)
                    printf("老年\n");
                else
                    printf("老不死\n");
            }
        }
    }

    //上下两种语句等价

    if (age < 18)
    {
        printf("未成年\n");
        printf("不能谈恋爱\n");

    }
    //当 if 语句中的表达式有多个，要括在大括号里形成代码块

//悬空 else
    int a = 0;
    int b = 2;
    if (a == 1)
        if (b == 2)
            printf("hehe\n");
    else
            printf("haha\n");
    //结论: else 和离它最近的 if 进行匹配，而与对齐无关
    //如果想要 else 和第一个 if 匹配，可以将第二个 if 用大括号括起来

// if 书写形式的对比
    // 1.
    // if (表达式 1)
    // {
    //      return x;
    // }
    // return y;
    //条件如果成立，返回 x ,条件如果不成立，返回 y
    // 2.
    // if (表达式 2)
    // {
    //      return x;
    // }
    // else
    // {
    //      return y;
    // }
    //上下两段代码表达的意义一致

    int a0 = TF();
    printf("%d\n", a0);
    // TF函数见文件开头

    //建议把常量放在 if 表达式的左面
    int num = 1;
    if (5 == num)
        printf("hehe\n");

// switch 语句
    //常常用于多分支的情况
    int day = 0;
    scanf("%d", &day);
    switch(day)//括号内必须是整形表达式
    {
        case 1:// case 整型常量表达式
            printf("星期 1\n");
            break;
        case 2:
            printf("星期 2\n");
            break;
        case 3:
            printf("星期 3\n");
            break;
        case 4:
            printf("星期 4\n");
            break;
        case 5:
            printf("星期 5\n");
            break;
        case 6:
            printf("星期 6\n");
            break;
        case 7:
            printf("星期天\n");
            break;
        default://以上全都不符合，推荐写
            printf("输入错误\n");
    }
    switch(day)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("工作日\n");
            break;
        case 6:
        case 7:
            printf("休息日\n");
            break;
    }
    // switch 语句中的 default 顺序可以任意选择(前、中、后均可)
    // case 语句中可以嵌套 if 语句，但是不能含有 continue
    // switch 语句可以嵌套使用
    /* switch case 语句中定义变量要加 {} */

    int n = 1;
    int m = 2;
    switch (n)
    {
        case 1:
            m++;
        case 2:
            n++;
        case 3:
            switch (n)
            {
                case 1:
                    n++;
                case 2:
                    m++;
                    n++;
                    break;
            }
        case 4:
            m++;
            break;
        default:
            break;
    }
    // m = 5  n = 3
//循环语句
    // while 语句
    // while (表达式)
    //     循环语句;
    int i = 0;
    while (i < 100)
    {
        if (10 == i)
            break;//循环不再继续

        i++;
        if (5 == i)
            continue;//终止本次循环，直接进行下一次循环(返回 while 进行判断)
        printf("%d\n", i);// 1 2 3 4 6 7 8 9 10
    }

    int ch0 = getchar();//此时 getchar 读取的是 \n
    int ch1 = getchar();//从键盘上接收一个字符
    putchar(ch1);//打印字符
    printf("%c\n", ch1);

    int ch2 = 0;
    while ((ch2 = getchar()) != EOF)// EOF - end of file - 文件结束标志
        putchar(ch2);
//注: clion 不能打 CTRL + D qwq

    int ret = 0;
    char password[20] = {0};
    printf("请输入密码:>");//输入缓冲区中含有 123456\n
    scanf("%s", password);// scanf 扫描 123456，缓冲区中剩余 \n
    getchar();// 读取 \n
    printf("请确认(Y/N):>");
    ret = getchar();//等待接收
    if ('Y' == ret)
        printf("确认成功\n");
    else
        printf("放弃确认\n");
    //只要想办法将缓冲区清空，就能让 getchar 接受键盘输入
    //如果输入 123456 ABCD的话呢?

    /*
    int ret0 = 0;
    char password0[20] = {0};
    printf("请输入密码:>");//输入缓冲区中含有 123456 ABCD\n
    scanf("%s", password0);// scanf 扫描 123456(空格前面的数据)，缓冲区中剩余 ABCD\n
    getchar();//读取 空格
    printf("请确认(Y/N):>");
    ret0 = getchar();//读取 'A'
    if ('Y' == ret0)// A != Y
        printf("确认成功\n");
    else
        printf("放弃确认\n");
    //......好像不太刑啊，再来再来
    */
    int ch = 0;
    int ret1 = 0;
    char password1[20] = {0};
    printf("请输入密码:>");
    scanf("%s", password1);
    while ((ch = getchar()) != '\n')
        ;
    printf("请确认(Y/N):>");
    ret1 = getchar();
    if ('Y' == ret1)
        printf("确认成功\n");
    else
        printf("放弃确认\n");

    int ch5 = 0;
    while ((ch5 = getchar()) != EOF)
    {
        if (ch5 < '0' || ch5 > '9')
            continue;
        putchar(ch5);
    }


    return 0;
}
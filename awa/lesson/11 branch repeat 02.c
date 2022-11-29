//
// Created by 86183 on 2022/9/17.
//
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

int main()
{
    // for 循环
    // while 循环的问题
    int i0 = 0;//初始化
    while (i0 < 10)//判断
    {
        //......;
        i0++;//调整......
    }
    // while 循环的三个可调整部分可能距离太远，不在一起

    //语法形式
    // for (exp1 ; exp2 ; exp3)
    //     循环语句;
    // exp1 用于初始化
    // exp2 用于条件判断
    // exp3 用于对循环条件的调整
    int i1 = 0;
    //   初始化     判断     调整
    for (i1 = 1; i1 <= 10; i1++)
    {
        if (5 == i1)
            continue;//注:不会死循环，continue 之后会直接执行 exp3
        printf("%d\n", i1);//循环体
        if (8 == i1)
            break;
    }
    //打印 1 2 3 4 6 7 8

    // for 循环的执行流程
    // 1. exp1 --> exp2 T/F?
    // 2.如果 T ，执行循环体；如果 F ，流程结束
    // 3.循环体执行后执行 exp3，再返回判断 exp2 T/F
    //重复 2

    // break 和 continue 可以用于 for 循环

// for 循环的几点注意
    // 1.不可在 for 循环体内改变循环变量，防止 for 循环失去控制
//    for (i1 = 1; i1 <= 10; i1++)
//    {
//        if (i1 = 5)
//            printf("hehe\n");
//        printf("haha\n");
//    }
    //导致死循环

    // 2.建议 for 循环的循环控制变量采取"前闭后开区间"的写法
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (i1 = 0; i1 < 10; i1++)//更好的了解这是 10 次循环，10 次打印，10 个元素
    {
        printf("%d\n", arr[i1]);
    }

//关于 for 循环的一些变种
    // 1. for(;;) 无尽循环
//    for(;;)
//    {
//        printf("hehe\n");
//    }
    // for 循环的初始化、调整、判断部分都可以省略
    //如果 for 循环的判断部分被省略，则判断条件恒为真
    //不熟练的话，建议不要随便省略
    int i = 0;
    int j = 0;
    for (; i < 10; i++)
    {
        for (; j < 10; j++)// j == 10 之后没有销毁，执行外层循环后仍为 10
        {
            printf("hehe\n");
        }
    }
    //只会打印 10 个 hehe

    // 2.两个变量的 for 循环
    int x, y;
    for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)// ++x x++ 此时没有区别
    {
        printf("hehe\n");
    }
    //只打印两个 hehe

    //这个循环要执行多少次?
    int a = 0;
    int b = 0;
    for (a = 0, b = 0; b = 0; a++, b++)
    {
        b++;
    }
    //判断语句中给 b 赋值为 0，为假，不进行循环

// do...while 循环
    //语法
//    do
//    {
//        循环语句;
//    }
//    while(表达式)
    //先执行，再判断，至少循环一次

    int i2 = 0;
    do
    {
        if (9 == i2)
            break;
        i2++;
        if (5 == i2)
            continue;
        printf("%d\n", i2);
    }
    while(i2 <= 10);
    // continue 可能死循环

    //计算 n 的阶乘
    int i3 = 0;
    int n = 0;
    long long a0 = 1;
    scanf("%d", &n);
    for (i3 = 1; i3 <= n; i3++)
    {
        a0 *= i3;
    }
    printf("%lld\n", a0);

    //计算 1！+2！+ ... + 10!
    int i4 = 1;
    int a1 = 0;
    int a2;
    for (i4 = 1; i4 <= 10; i4++)
    {
        int i5 = i4;
        a2 = 1;
        for (;i5 >= 1; i5--)
        {
            a2 *= i5;
        }
        a1 += a2;
    }
    printf("%d\n", a1);
    //看着有点复杂，来把它优化一下吧
    int i6 = 1;
    int a3 = 1;
    int sum = 0;
    for (i6 = 1; i6 <= 10; i6++)
    {
        a3 *= i6;
        sum += a3;
    }
    printf("%d\n", sum);
    //实际上简化了运算过程，利用了之前的和
    //前面的思路:1 * 1 + 1 * 2 + 1 * 2 * 3 ......
    //后面的思路:1 * 1 + 1 * 2 + 2 * 3 + 6 * 4 ......

    int arr0[] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11};
    //写一个代码，在 arr 数组(有序的)中找到 7
    // 1.按顺序查找(效率很低)
    int k = 10;
    int i5 = 0;
    int sz = sizeof(arr0) / sizeof(arr0[0]);
    for (i5 = 0; i5 < sz; i5++)
    {
        if (k == arr[i5])
        {
            printf("找到了，下标是:%d\n", i5);
            break;
        }
    }
    if (i5 == sz)
        printf("找不到\n");

    // 2.二分查找算法(折半查找算法)
   int left = 0;
   int right = sz - 1;
   int mid;
   scanf("%d", &k);
   for(;left <= right;)//条件
   {
       mid = (left + right) / 2;
       if (arr0[mid] > k)
           right = mid - 1;
       else if (arr0[mid] < k)
           left = mid + 1;
       else
       {
           printf("找到了，下标是:%d\n", mid);
           break;
       }
   }
    if (left > right)
        printf("找不到\n");

    // welcome to bit !!!!!!
    // w###################!
    // we#################!!
    // wel###############!!!
    // ...
    char arr1[] = "welcome to bit !!!!!!";
    char arr2[] = "#####################";
    int left0 = 0;
    int right0 = sizeof(arr1) / sizeof(arr1[0]) - 2;//注意要减 2 ,因为字符串中有 \0
    //有点麻烦，换种写法吧
    right0 = strlen(arr1) - 1;

    while (left0 <= right0)
    {
        arr2[left0] = arr1[left0];
        arr2[right0] = arr1[right0];
        printf("%s\n", arr2);
        //休息一秒
        Sleep(1000);
        system("cls");//执行系统命令的一个函数  cls - 清空屏幕
        left0++;
        right0--;
    }

    int i7 = 0;
    char password[20] = {0};
    for (i7 = 0; i7 < 3; i7++)
    {
        printf("请输入密码:>");
        scanf("%s", password);
        if (strcmp("123456", password) == 0)// == 不能比较两个字符串是否相等，应该使用一个库函数 - strcmp
        //如果两个字符串相等，函数返回 0
        {
            printf("登录成功\n");
            break;
        }
        else
        {
            printf("密码错误\n");
        }
    }
    if (3 == i7)
    {
        printf("给你机会你不中用啊\n");
    }

// goto 语句
    //建议不要使用 goto 语句

    printf("hello bit\n");
    goto again;
    printf("你好\n");
again:
    printf("hehe\n");
    // goto 语句会打乱原有代码的执行顺序
    // goto 语句的作用：跳出多层嵌套，直接来到最外层

    //一个关机程序
    // shutdown -s -t 60  60 秒之后关机
    // shutdown -a  取消关机
    // system() - 执行系统命令的函数

    char input[20] = {0};
    system("shutdown -s -t 60");
again0:
    printf("请注意，你的电脑将在 1 分钟内关机，如果输入:我是猪，就取消关机\n请输入:>");
    scanf("%s", input);
    if (strcmp(input, "我是猪") == 0)
    {
        system("shutdown -a");
    }
    else
    {
        goto again0;
    }
    return 0;
}



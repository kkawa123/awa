//
// Created by 86183 on 2022/9/22.
//
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <math.h>

//调用头文件
#include "../.h/add.h"

int get_max(int x, int y)// int 表示函数返回一个整型
{
    return (x > y ? x : y);
}

void Swap1(int x, int y)// void 表示函数不需要返回值
//由于 x, y 有自己的独立空间(与 a, b 地址不同)，改变 x, y 不会影响 a 和 b
//这种方法只能交换 x, y ，不能交换原本的 a 和 b
{
    int tmp = 0;
    tmp = x;
    x = y;
    y = tmp;
}
//失败

void Swap2(int* pa, int* pb)
{
    int tmp = 0;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}
//将地址传输至函数中
//通过指针变量，远程操作更改 a, b 的值
//成功

int Judge(int x)
{
    int i = 1;
    for(i = 2; i < sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int Judge0(int x)
{
    if ((x % 400 == 0) || ((x % 4 == 0) && (x % 100 != 0)))
        return 1;
    else
        return 0;
}
                      //本质上 arr 是一个指针
int array_find(int x, const int arr[], int sz)
                      //为什么 const int *arr[] 不行？
                      //指针所占空间是 8，因此直接传输不能得到元素个数
                      //直接传输元素个数
{
    int left = 0;
    int right = sz - 1;


    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (x > arr[mid])
            left = mid + 1;
        else if (x < arr[mid])
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

void Add0(int* p)
{
    (*p)++;//注：不打括号会变成 p++
}

void new_line()
{
    printf("hehe\n");
}

void three_line()
{
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        new_line();
    }
}




int main()
{
//函数

    int a = 10;
    int b = 20;
    int sum = Add(a, b);
    printf("%d\n", sum);

    //分类
    // 1. C 语言本身提供给我们的函数 - 库函数
    //常用的库函数：I/O 函数，字符(串)操作函数，内存操作函数，时间/日期函数，数学函数，其他
    // strlen - string length - 字符串长度有关
    // strcpy - string copy - 字符串拷贝

    char arr1[] = "bit";
    char arr2[20] = "############";
    strcpy(arr2, arr1);//将 arr1 里的内容拷贝到 arr2
    printf("%s\n", arr2);//只是替换了前四个字符，因为有 \0 就停止打印了
    //源头比目的地要长，就会溢出

    // memset (void* ptr, int value, size_t num) - 把 ptr 指向的地址(内存块)的前 num 个字节设置成 value
    // memory - 内存  set - 设置
    char arr[] = "hello world";//要求:把 hello 改成 *****
    memset(arr, '*', 5);//字符传输的 ASCII 码值是整型
    printf("%s\n", arr);

//函数的组成
    //返回类型 - 函数名 - 函数参数
    // {
    //函数体 - 交代的是函数的实现
    // }

    //写一个函数找出两个数的最大值

    int a0 = 10;
    int b0 = 20;
    int max = get_max(a0, b0);
    printf("max = %d\n", max);
    int max0 = 0;
    max0 = get_max(100, 300);
    printf("%d\n", max0);//应用于常量

    //写一个函数交换两个整形的内容
    int a1 = 10;
    int b1 = 20;
    printf("a1 = %d b1 = %d\n", a1, b1);
    Swap1(a1, b1);//调用 Swap1 函数
    printf("a1 = %d b1 = %d\n", a1, b1);

    //指针变量的复习
    int a2 = 10;
    int* pa = &a2;// pa - 指针变量
    *pa = 20;//解引用操作
    printf("%d\n", a2);

    Swap2(&a1, &b1);//调用 Swap2 函数
    printf("a1 = %d a2 = %d\n", a1, b1);

    //函数参数的类型
    // 1.实际参数(实参):真实传给函数的参数，可以是常量，变量，表达式(要能算出确定的值)，函数(只要函数能算出确定值，如 get_max(3, 7))等，必须有确定的值，以传送给形参
    // 2.形式参数(形参):函数名后括号中的变量，只有再函数调用时被实例化，函数调用结束后被销毁
    //上面实例中实参为 a1, b1, &a1, &b1, 形参为 *pa, *pb, x, y
    //实参和形参使用的通常不是同一空间(地址)
    //形参实例化后相当于实参的一份临时拷贝，对形参的改变不会影响实参

    //函数的调用
    // 1.传值调用:函数的形参和实参分别占有不同的内存块，对形参的修改不会影响实参 - Swap1
    // 2.传址调用:把函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式。这种传参方式可以让函数和函数外边的变量建立起真正的联系，也就是函数内部可以直接操作函数外部的变量 - Swap2
    //传值 / 传址？观察是否需要改变实参

//练习
    // 1.写一个函数判断一个数是否为素数
    int num = 0;
    scanf("%d", &num);
    int bool = Judge(num);
    if (1 == bool)
        printf("是素数\n");
    else
        printf("不是素数\n");

    // 2.写一个函数判断一年是否为闰年
    int year = 0;
    scanf("%d", &year);
    if (1 == Judge0(year))
        printf("是闰年\n");
    else
        printf("不是闰年\n");

    // 3.写一个函数，实现一个整形有序数组的二分查找
    //找到了返回下标，找不到返回 -1
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 7;
    int sz = sizeof(array) / sizeof(array[0]);
                               //注意:数组在传参过程中传输的仅仅是数组首元素的地址
    if (-1 != array_find(k, array, sz))
        printf("找到了，下标是:%d\n", array_find(k, array, sz));
    else
        printf("找不到\n");

    // 4.写一个代码，调用一次函数，num 就增加 1
    int num0 = 0;
    Add0(&num0);
    printf("num0 = %d\n", num0);
    Add0(&num0);
    printf("num0 = %d\n", num0);
    Add0(&num0);
    printf("num0 = %d\n", num0);

    //函数的嵌套调用和链式访问
    //嵌套调用
    three_line();//函数体见前
    //链式访问 - 把一个函数的返回值作为另一个函数的参数
    // 1.
    int len = 0;
    len = strlen("abc");
    printf("%d\n", len);
    // 2.
    printf("%d\n", strlen("abc"));

    printf("%d\n", printf("%d", printf("%d", 43)));// 4321
    // printf 函数的返回值是成功打印的字符个数

    //函数的声明和定义

    //函数的调用
    int a10 = 10;
    int b10 = 20;
    int sum10 = 0;
    sum10 = Add(a10, b10);
    printf("%d\n", sum10);
    //加法模块的实现
    // 1.函数的定义放入 .c 文件中
    // 2.函数的声明放入 .h 文件中
    // 3.在要使用的文件中引用 .h 头文件

    //函数的声明：告诉编译器有一个函数叫什么，参数是什么，返回类型是什么，但是具体是不是存在无关紧要
    //函数的声明一般出现在函数的使用之前，满足先声明后使用
    //函数的声明一般放在头文件中
    //函数的定义是指函数的具体实现，支持函数的功能实现

    return 0;
}
//要想函数返回两个数据给主调函数，形参可以用数组或者两个指针
// C 语言不能直接返回数组，但是可以返回数组的一维指针
//
// Created by 86183 on 2022/9/9.
//
# include <stdio.h>
# include <stdlib.h>

void test()
{
    static int x = 1;// a 是一个静态的局部变量
    x++;
    printf("x = %d\n", x);
}
#define MAX(X, Y)  ((X) > (Y) ? (X) : (Y)) //前面定义的宏会被替换成后面的表达式
// MAX 后面不能有空格
int main()
{
//关键字

    // auto
    auto int a = 10;//局部变量，自动变量 - 自动创建，自动销毁
    // auto 可以省略

    // break case char const continue
    // default 默认
    // do double else enum(枚举)
    // extern 引入外部语句
    // float for goto(语句)
    // if int long

    // register 寄存器关键字
    register int a1 = 10;//建议把 a 定义成寄存器变量，将 a 放到寄存器中

    // return short

    // signed 定义有符号数
    signed int a2 = 10;// int 定义的变量是有符号的
    a2 = -2;
    // unsigned 定义无符号数
    unsigned int a3 = -1;
    printf("%u\n", a3);// %u 无符号整数

    // sizeof static(静态的)
    // struct 结构体关键字
    // switch typedef(类型定义)
    // union - 联合体/共用体
    // void 无/空
    // volatile
    // while 循环

    // typedef 类型定义/类型重定义
    typedef unsigned int u_int;//将 unsigned int 别名为 u_int
    unsigned int num = 20;
    u_int num2 = 10;
    //上下等价

    // static
    int i = 0;
    while (i < 5)
    {
        test();
        i++;
    }
    //不加 static ，打印结果是 5 个 2
    //加上 static ，打印结果是 2 3 4 5 6
    // static 修饰局部变量，使局部变量的生命周期变长，使其出了作用域依然存在直到程序结束
    // static 修饰全局变量，改变了静态的全局变量的作用域，让其只能在自己的源文件内部使用，出了源文件就无法再使用了
    extern int g_val;
    printf("%d\n", g_val);//加了 static 会报错

    // static 修饰函数
    extern int Add(int, int);
    int a0 = 10;
    int b0 = 20;
    int sum = Add(a0, b0);
    printf("sum = %d\n", sum);
    //同理加上 static 报错
    // static 修饰函数，改变了函数的链接属性
    //正常的一个函数是具有外部链接属性的，加上 static 变成了内部链接属性

// #define 定义常量和宏
    // #define 定义标识符常量
// #define MAX 100
    // #define 定义宏
    // 1.函数的方式
    extern int Max(int, int);
    int a5 = 10;
    int b5 = 20;
    int max1 = Max(a5, b5);
    printf("max1 = %d\n", max1);
    // 2.宏的方式
    // #define 见源文件开头
    int max2 = MAX (a5, b5);
    printf("max2 = %d\n", max2);

    return 0;
}
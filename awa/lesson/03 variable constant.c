//
// Created by 86183 on 2022/9/8.
//
#include <stdio.h>

int a = 10;//全局变量 - 定义在代码块{}之外的变量
int main() {
    int age = 150;//定义变量的方式
    int a = 20;//局部变量 - 定义在代码块{}之内的变量，不一定在 main 函数里

    printf("%d\n", a);
    //全局变量未初始化默认是 0
    //局部变量和全局变量的名字建议不要相同 - 容易误会，产生 bug
    //当局部变量和全局变量名字相同的时候，局部变量优先
    //局部变量不能在{}外使用

//计算两个数的和
    int num1 = 0;
    int num2 = 0;
    //输入数据 - 使用输入函数 scanf
    scanf("%d%d", &num1, &num2);// & 取地址符号
    // scanf 是C语言提供的， scanf_s 是VS提供的，使用后者会降低代码的可移植性
    int sum = 0;
    sum = num1 + num2;
    printf("sum = %d\n", sum);
    //C语言语法规定，变量要定义在当前代码块的最前面（但现在好像不用。。。？）
//作用域 - 变量哪里能用哪里就是作用域
    //局部变量的作用域 - 当前代码块
    {
        int num = 0;
    }
    //printf("num = %d\n", num);//报错：未定义
    //全局变量的作用域 - 整个工程
    //假设在本项目其他文件中有全局变量
    extern int g_val;// extern 声明外部符号
    printf("g_val = %d\n", g_val);//未声明的标识符 --> 声明
//变量的生命周期
    //局部变量的生命周期 - 进入作用域生命周期开始，出作用域生命周期结束
    {
        int f = 10;
        printf("f = %d\n", f);//ok
    }
    //printf("f = %d\n", f) // error
    //全局变量的生命周期 - 整个程序的生命周期
//常量
    //1.字面常量
    33;
    100;
    3.14;
    //2. const - 常属性
    // const 修饰的常变量
    const int num = 4;//此时 num 不能被修改，n 是变量，但是又有常属性，所以说 n 是常变量
    printf("%d\n", num);
    // num = 8;//error
    printf("%d\n", num);
    //3. #define 定义的标识符常量
#define MAX 10 //定义常量 MAX 为 10
    //4.枚举常量 - 一一列举
    //例：性别：男，女，保密
    //星期：1，2，3，4，5，6，7
    //三原色：RGB
    enum Sex // enum - 枚举关键字
    {
        MALE,
        FEMALE,
        SECRET
    };
    // MALE,FEMALE,SECRET - 枚举常量
    enum Sex s = FEMALE;// s 表示某个人的性别
    printf("%d\n", MALE);// 0
    printf("%d\n", FEMALE);// 1
    printf("%d\n", SECRET);// 2

    enum Color
    {
        RED,
        GREEN,
        BLUE
    };
    enum Color color = BLUE;
    //定义 color 为 BLUE
    color = GREEN;// color 可变，BLUE 不能改
    return 0;
}
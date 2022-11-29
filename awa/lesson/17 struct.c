//
// Created by 86183 on 2022/10/21.
//
/*  结构体  */

#include <stdio.h>

//定义结构体 - 描述一个学生 - 一些数据
//姓名 - 年龄 - 电话 - 性别
// struct - 结构体关键字
struct Stu // Stu - 结构体标签   struct Stu - 结构体类型
{
    //成员变量
    char name[20];
    short age;
    char tele[12];
    char sex[5];
} s1, s2, s3;//分号不能丢
// s1, s2, s3 是三个全局的结构体变量 - 尽量少用
//创建的类型不占用内存空间

//第二种写法
typedef struct Stu0
{
    char name[20];
    short age;
    char tele[12];
    char sex[5];
}Stu0;
//将 struct Stu0 重命名为 Stu0，此时 Stu0 是类型

struct S
{
    int a;
    char c;
    char arr[20];
    double d;
};

struct T
{
    char ch[10];
    struct S s;
    char* pc;
};

void Print1(Stu0 tmp)
{
    printf("name:%s\n", tmp.name);
    printf("age:%d\n", tmp.age);
    printf("tele:%s\n", tmp.tele);
    printf("sex:%s\n", tmp.sex);
}

void Print2(Stu0* ps)
{
    printf("name:%s\n", ps -> name);
    printf("age:%d\n", ps -> age);
    printf("tele:%s\n", ps -> tele);
    printf("sex:%s\n", ps -> sex);
}

int Add(int x, int y)
{
    int z = x + y;
    return z;
}

int main()
{
//一、结构体类型的声明

    //结构的基础知识
    //结构是一些值的集合，这些值被称为成员变量，结构的每个成员可以是不同类型的变量

    //结构的声明
    {
        struct Stu s;//创建结构体变量 - 局部变量
    }

    //结构成员的类型
    //可以是标量(普通变量)，数组，指针，甚至是其他结构体

//二、结构体变量的定义和初始化

    //变量的定义 1.在创建结构体类型的后边定义 2.在调用结构体的时候进行定义
    //初始化
    struct Stu stu1 = {"张三", 20, "15249287076", "男"};
    struct Stu stu2 = {"旺财", 30, "15599668862", "女"};
    //嵌套结构体的初始化
    char arr[] = "hello bit";
    struct T t = {"hehe", {100, 'w', "hello world", 3.14}, arr};

//三、结构体成员访问
//四、结构体传参

    printf("%s\n", t.ch);// hehe
    printf("%s\n", t.s.arr);// hello world
    printf("%lf\n", t.s.d);// 3.14
    printf("%s\n", t.pc);// hello bit
    //结构体成员的访问通过 .(点操作符)和 ->(箭头操作符)完成

    Stu0 s = {"李四", 40, "15598886688", "男"};
    Print1(s);
    Print2(&s);
    //打印结构体 - 可以传 s 也可以传 &s
    //传 &s 比较好 - 不占额外空间，不会因为结构体过大，压栈导致性能下降

//五、额外内容

    int a = 10;
    int b = 20;
    int ret = Add(a, b);//先传 b，再传 a
    printf("%d\n", ret);

    //栈区 - 局部变量，函数的形参，函数调用也会开辟空间
    //堆区 - 动态内存分配，malloc, free, realloc, calloc
    //静态区 - 全局变量，静态变量

    //数据结构:
    //一、线性数据结构
    // 1.顺序表 - 1, 2, 3, 4, 5, 6, ... 按顺序排列，放置再内存的一整块区域(类似数组？)
    // 2.链表 - 1 ------- 2 ------- 3 ... 也是按顺序排列，但是各个数据在内存中随意放置

    //         ...
    //          3
    //          2
    //          1
    // 3.栈      0   只能从栈顶进，栈顶出(类似步枪弹夹)  出栈(删除数据)的时候只能依次从栈顶删除
    //               特点：先进后出，后进的先出
    //               插入一个元素 - 压栈   删除一个元素 - 出栈  传参的时候就是压栈
    // 4.队列

    //二、树形数据结构
    // 二叉树

    //三、图

    return 0;
}




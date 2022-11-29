//
// Created by 86183 on 2022/9/11.
//

//结构体
//描述 人/书 - 复杂对象
//名字 + 身高 + 年龄 + 身份证号码......
//书名 + 作者 + 出版社 + 定价 + 书号
//描述复杂对象 - 创建结构体 - 我们自己创造出来的一种类型
//创建一个结构体类型
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book
{
    char name[20];// C语言程序设计
    int price;
};// ; 结束类型定义，不可缺少

int main()
{
    system("chcp 65001");
    //利用结构体类型，创建结构体变量
    struct Book A = {"C语言程序设计", 55};
    printf("书名:%s\n", A.name);
    printf("价格:%d元\n", A.price);

    A.price = 15;
    printf("修改后的价格:%d元\n", A.price);
    struct Book* pb = &A;
    //利用 pb 打印书名和价格
    printf("%s\n", (*pb).name);
    printf("%d\n", (*pb).price);

    printf("%s\n", pb -> name);
    printf("%d\n", pb -> price);
    // . 结构体变量.成员
    // -> 结构体变量 -> 成员

    //改变结构体中的书名
    strcpy(A.name, "C++");
    // strcpy - string copy - 字符串拷贝 - 库函数 - string.h
    printf("书名:%s\n", A.name);

    return 0;
}
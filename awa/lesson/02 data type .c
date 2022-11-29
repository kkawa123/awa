//
// Created by 86183 on 2022/9/8.
//

//数据类型
// char - 字符数据类型 a b c...
// short - 短整型
// int - 整型
// long - 长整型
// long long - 更长的整型
// float - 单精度浮点数
// double - 双精度浮点数 精度高
#include <stdio.h>
int main()
{
    char ch = 'A';// char 是字符类型，向内存申请了一块空间 ch 用于存放 A
    printf("%c\n", ch);// %c - 打印字符格式的数据

    //貌似字符中只能有一个字母，如果有多个则打印最后一个
    // ch 可以随意进行替换

    int age = 20;// short int age = 20
    printf("%d\n", age);// %d - 打印整型十进制数据
    //同理 age 也可替换

    float B = 5.0f;
    printf("%f\n", B);// %f - 打印浮点型
    // float 可以精确到小数点后8(?)位

    double C = 3.14;
    printf("%lf\n", C);// %lf 表示长精度 long float
    // double 可以精确到小数点后16(?)位

//为什么要设定各种数据类型呢？
    printf("%d\n", sizeof(char));// 1 字节
    printf("%d\n", sizeof(short));// 2 字节 - 2的16次方，到65535
    printf("%d\n", sizeof(int));// 4
    printf("%d\n", sizeof(long));// 4/8 - C 语言标准规定 sizeof(long) >= sizeof(int)
    printf("%d\n", sizeof(long long));// 8
    printf("%d\n", sizeof(float));// 4
    printf("%d\n", sizeof(double));// 8
    //占用的空间不同

    short age2 = 20;//像内存申请2个字节 = 16 bit 位，用来存放 20
    float weight = 95.6f;//系统默认浮点型为 double,后加 f 可以标定其为 float
    return 0;
}
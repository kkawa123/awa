//
// Created by 86183 on 2022/9/8.
//
#include <stdio.h>

int Add(int x, int y)
{
    int z = x + y;
    return z;
}
//函数体

int main()
{
//函数
    //库函数
    //自定义函数 - 自己的创造
    int a = 100;
    int b = 200;
    int sum = 0;
    sum = Add(a, b);// Add：自定义函数，需要在文件开头创建函数体
    printf("sum = %d\n", sum);
    //之后可以使用 sum(a, b) 进行任意相加

//数组 - 一组相同类型元素的集合
    //char ch[20];
    //float arr2[5];
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//定义一个存放 10 个整数数字的数组
    printf("%d\n", arr[4]);// 5
    //用下标的方式访问元素，下标默认从 0 开始
    //数组的大小要用常量来指定
    //方括号中不指定数值的时候会自动根据后面的内容进行初始化
    //打印数组中所有元素
    int i = 0;
    while (i < 10)
    {
        printf("%d\n", arr[i]);
        i++;
    }
//操作符
    //算术操作符
    // +  -  *  /  %(取余)
    int c = 5 / 2;// 2
    int d = 5 % 2;// 1
    printf("%d\n%d\n", c, d);

    //移(二进制)位操作符
    // << 左移
    // >> 右移
    int m = 1;
    //整型 1 占四个字节 -  000000000000000000000000000000001
    int o = m << 1;//变为 000000000000000000000000000000010
    int p = m << 2;// 变为 000000000000000000000000000000100
    printf("%d\n", o);// 2
    printf("%d\n", p);// 4
    //此时 a 仍然为 1，不变

    //(二进制)位操作符
    // & 按位与
    // | 按位或
    // ^ 按位异或
    int k = 3;// 011
    int l = 5;// 101
    int j = k & l;// 001
    printf("%d\n", j);// 1
    int h = k | l;// 111
    printf("%d\n", h);// 7
    int g = k ^ l;// 110
    printf("%d\n", g);// 6

    //赋值操作符
    // =  +=  -=  *=  /=  ^=  |=  >>=  <<=
    //复合赋值符
    int u = 0;
    u = 10;// = 赋值   == 判断相等
    u += 10;// u = u + 10
    u -= 10;// u = u - 10
    u = u & 2;// u &= 2

    //单目操作符

    int v = 10;
    int r = 0;
    v + r; // + 双目操作符 - 有两个操作数 a 和 b
    // ！逻辑反操作
    // C 语言中表示真假   0 - 假
    //               非 0 - 真
    printf("%d\n", v);// 10
    printf("%d\n", !v);// 0
    printf("%d\n", !r);// 1
    // - 负号 - 取负
    // + 正号 一般省略
    // & 取地址
    // sizeof 计算的是变量/类型所占空间的大小，单位是字节
    printf("%d\n", sizeof(v));// 4
    printf("%d\n", sizeof(int));// 4
    printf("%d\n", sizeof v);// 4
    // 变量可以省略()，int 不能

    int arr3[10] = { 0 };// 10 个整形元素的数组
    printf("%d\n", sizeof(arr3));// 40
    //计算数组的元素个数
    //个数 = 数组总大小 / 每个元素的大小
    int sz = 0;
    sz = sizeof(arr3) / sizeof(arr[0]);
    printf("sz = %d\n", sz);// 10

    // ~ 对一个数的二进制数按位取反
    int x = 0; // 00000000000000000000000000000000
    int y = ~x;// 11111111111111111111111111111111 补码
    printf("%d\n", y);// -1
    //原码、反码、补码
    //只要是整数，内存中存储的都是二进制的补码
    //正数的原码、反码、补码相同
    //负数在内存中存储的时候，存储的是二进制的补码
    // y 是有符号的整型，二进制位的第一位是符号位，0 代表正数，1 代表负数
    //补码 - 1 = 反码 11111111111111111111111111111110
    //反码取反得到原码，符号位不变 10000000000000000000000000000001 --> -1
    // printf 打印的是这个数的原码
    //有符号数的范围是 -2^(n-1)-1 ~ 2^(n-1)-1
    //无符号数的范围是 0 ~ 2^n-1

    // ++ --
    int a1 = 10;
    int b1 = a1++;//后置++，先使用，再++
    printf("a1 = %d b1 = %d\n", a1 ,b1);// 11 10
    int c1 = ++a1;//前置++，先++，再使用
    printf("c1 = %d\n", c1);// 12
    int d1 = a1--;
    printf("a1 = %d d1 = %d\n", a1, d1);// 11 12
    int e1 = --a1;
    printf("a1 = %d e1 = %d\n", a1, e1);//10 10

    // * 间接访问操作符/解引用操作符
    // (类型) 强制类型转换
    int a2 = (int)3.14;//将 3.14 强制转换成整型

    //双目操作符
    //三目操作符

    //关系操作符
    // > >= < <= != 用来判断“不相等” == 用来判断“相等”

    // && 逻辑与
    int a3 = 3;
    int b3 = 5;
    int c3 = a3 && b3;
    printf("c3 = %d\n", c3);// 1 代表真
    a3 = 0;
    int c4 = a3 && b3;
    printf("c4 = %d\n", c4);// 0 代表假

    // || 逻辑或
    int c5 = a3 || b3;
    printf("c5 = %d\n",  c5);// 1 代表真
    b3 = 0;
    int c6 = a3 || b3;
    printf("c6 = %d\n", c6);// 0 代表假

    //条件操作符，三目操作符
    // exp1 ? exp2 : exp3
    int a4 = 10;
    int b4 = 20;
    int max1 = 0;
    if (a4 > b4)
        max1 = a4;
    else
        max1 = b4;
    printf("max1 = %d\n", max1);

    max1 = a4 > b4 ? a4 : b4;
    printf("max1 = %d\n", max1);
    //上下两个表达式等价
    //判断：a4 > b4 吗？如果成立，输出 a4；如果不成立，输出 b4

    //逗号表达式
    //exp1, exp2, exp3, ...expN

    //下标引用操作符 []
    int arr0[10] = { 0 };
    printf("%d\n", arr0[0]);// [] - 下标引用操作符

    //函数调用操作符 ()
    int a5 = 10;
    int b5 = 20;
    Add(a5, b5);//函数调用
    //函数体见文件开头

    // . -> 结构成员








    return 0;
}
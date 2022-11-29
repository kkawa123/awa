//
// Created by 86183 on 2022/10/5.
//

#include <stdio.h>
#include <string.h>


void print(int n)
{
    if (n > 9)
    {
        print(n / 10);
    }
    printf("%d ", n % 10);
}
//寄巧：利用 /  % 分割数字

int my_strlen1(char* str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

int my_strlen2(char* str)
{
    if (*str != '\0')
        return 1 + my_strlen2(str + 1);//注：str++ 会先返回 str 再 ++ ，导致无限递归
    else                        //震惊：指针可以加
        return 0;
}

int Fac1(int x)
{
    int tmp = 1;
    for (; x >= 1; x--)
    {
        tmp *= x;
    }
    return tmp;
}

int Fac2(int x)
{
    if (x >= 1)
        return (x * Fac2(x - 1));
    else
        return 1;
}

int Fib1(int x)
{
    if(x <= 2)
        return 1;
    else
        return Fib1(x - 1) + Fib1(x - 2);
}
// 50
// 49 48
// 48 47 47 46
// 47 46 46 45 46 45 45 44
// ...
//计算量太大，重复次数多，算法差
//不适合用递归计算

int Fib2(int x)
{
    int n = 1;
    int a = 1;
    int b = 1;
    int c = 1;
    while(n <= x - 2)
    {
        c = a + b;
        n++;
        a = b;
        b = c;
    }
    return c;
}
//循环解 - 速度快

int main()
{
//递归 - 程序调用自身
//把一个大型复杂的问题层层转化为一个与原问题相似的规模较小的相似问题来求解，有效减少代码量
//基本思想 - 把大事化小
    printf("hehe\n");
    // main();
    //注：无限递归会导致栈溢出
    //栈区 - 存放局部变量和函数形参，函数调用会向栈区申请空间 - stack overflow
    //堆区 - 动态开辟的内存 (?)
    //静态区 - 存放全局变量和 static 修饰的变量

    //输入无符号的整形数，按顺序输出它的每一位

    int num = 0;
    scanf("%d", &num);
    print(num);

    //递归的必要条件
    // 1.存在限制条件，当满足这个限制条件之后，递归便不再继续
    // 2.每次调用之后越来越接近这个限制条件
    //单调有界

    //编写一个函数，不允许创建临时变量，求字符串的长度

    char arr[] = "bit";
//    int len = strlen(arr);
//    printf("%d\n", len);
    int len = my_strlen2(arr);
    printf("len = %d\n", len);

    //迭代

    //求 n 的阶乘

    int n = 0;
    scanf("%d", &n);
    int ret1 = Fac1(n);//循环
    printf("%d\n", ret1);
    int ret2 = Fac2(n);//递归
    printf("%d\n", ret2);

    int tmp = 1;
    int x = 5;
    tmp *= x * --x;// 4 * 4
    printf("%d\n", tmp);//显然在编译器中的 -- 优先级最高，默认先 -- 再给 x 赋值

    //求第 n 个斐波那契数

    int b = 0;
    scanf("%d", &b);
    int fib1 = Fib1(b);
    printf("%d\n", fib1);
    int fib2 = Fib2(b);
    printf("%d\n", fib2);

    //如果递归的运行效率很低，选用循环写法




    return 0;


}
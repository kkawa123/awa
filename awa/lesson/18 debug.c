//
// Created by 86183 on 2022/10/24.
//
#include <stdio.h>
#include <memory.h>
#include <assert.h>

int Add(int x, int y)
{
    return (x + y);
}

void test2()
{
    printf("hehe\n");
}

void test1()
{
    test2();
}

void test()
{
    test1();
}

void my_strcpy1(char* dest, char* src) //初版
{
    for (; *src != '\0'; src ++, dest ++)
    {
        *dest = *src;
    }
    *dest = * src;
}

void my_strcpy2(char* dest, char* src) //修改第 1 版
{
    while (*dest ++ = *src ++) // *src == 0 的时候赋值为 0，为假
    {
        ;
    }
}

void my_strcpy3(char* dest, char* src) //修改第 2 版
{
    if (dest != NULL && src != NULL) //防止传入空指针导致程序崩溃
    {
        while (*dest ++ = *src ++)
        {
            ;
        }
    }
}

void my_strcpy4(char* dest, char* src) //修改第 3 版
{
    assert(dest != NULL);//断言 - 表达式为假会报错 - 便于判断某个条件的正确性
    assert(src != NULL);// assertion "src != NULL" failed: file "/cygdrive/c/Users/86183/Desktop/awa/lesson/18 debug.c", line 59, function: my_strcpy4
    while (*dest ++ = *src ++)
    {
        ;
    }
}

void my_strcpy5(char* dest, const char* src) //修改第 4 版
{                           //使成为常变量 - 防止源中的内容(*src)被修改
    assert(dest != NULL);
    assert(src != NULL);
    while (*dest ++ = *src ++)
    {
        ;
    }
}

char* my_strcpy6(char* dest, const char* src) //修改第 5 版
{
    char* ret = dest;
    assert(dest != NULL);
    assert(src != NULL);
    //把 src 指向的字符串拷贝到 dest 指向的空间，包含 '\0' 字符
    while (*dest ++ = *src ++)
    {
        ;
    }
    return ret;//直接返回目标的地址，便于打印
}

int my_strlen(const char* str)
{
    int count = 0;
    assert(str != NULL);//保证指针的有效性
    while (*str ++)
    {
        count ++;
    }
    return count;
}

int main()
{
//调试(debug)，又称除错，是发现和减少计算机程序或电子仪器设备中程序错误的一个过程

    //调试的基本步骤
    // 1.发现程序错误的存在 - 程序猿   -   测试开发    -    用户
    //                    写程序     测试程序的正确性     使用
    // 2.以隔离、消除等方式对错误进行定位
    // 3.确定错误产生的原因
    // 4.提出纠正错误的解决办法
    // 5.对程序错误予以改正，重新测试

    // Debug 通常称为调试版本，通常不做任何优化，便于程序员调试程序
    // Release 称为发布版本，往往进行了各种优化，使得程序在代码大小和运行速度上都是最优的，以便用户更好的使用
    // Debug - Debug 版本的可执行程序 - 可以调试，文件中包含了调试信息
    // Release - Release 版本的可执行程序 - 不能进行调试
    //测试测的是 release 版本

    {
        int i = 0;
        for (i = 0; i < 100; i ++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }

    {/*
        int i = 0;
        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (i = 0; i <= 12; i ++)
        {
            printf("hehe\n");
            arr[i] = 0;
        }

    */}
    // Debug 版本执行会死循环而 Release 版本不会
    //断点 - 代码运行到这里会停下来
    //运行 - shift + f10
    //调试 - shift + f9
    //设置断点 - ctrl + f8

    //调试
    //步过 - 不管该行代码是否有函数，直接运行到下一行代码
    //步入 - 该行代码若无函数，则作用与步过相同。若有函数，则进入该函数的第一行代码
    //强制单步执行 - 当调用了一个类库方法的时候，强制进入会进入到该类库的方法里面(反汇编)
    //步出 - 若执行的代码是所定义的函数，则直接将函数执行完并且跳出该函数(或运行到下一个断点)

    //步入
    {
        int a = 10;
        int b = 20;
        int c = Add(a, b);
        printf("%d\n", c);
    }

    {
        int arr[10] = { 0 };
        int i = 0;
        for (i = 0; i < 10; i ++)
        {
            arr[i] = i;
        }
    }

    //调用堆栈 - 像栈一样显示出程序的数据结构
    {
        test();
    }

    //有问题的代码 - 求 1! + 2! + ... + n!
    {
        int i = 0;
        int sum = 0;
        int n = 0;
        scanf("%d", &n);
        for (i = 1; i <= n; i ++)
        {
            int j = 0;
            int ret = 1;
            for (j = 1; j <= i; j ++)
            {
                ret *= j;
            }
            sum += ret;
        }
        printf("%d\n", sum);
    }

    /* 一个死循环的程序 */
    {
        int i = 0;
        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        printf("%p\n", &arr);// &arr[10] == &i - 一块空间
        printf("%p\n", &i);
        int count = 0;
        for (i = 0; i <= 12; i++) //越界访问
        {
            printf("hehe\n");
            arr[i] = 0;
        }
    }
    //调试的时候会用到另外一个地址(？) - 栈区的空间变化
    //解释 -
    // 1.栈区的默认使用：先使用高地址处的空间，再使用低地址处的空间
    // 2.数组随着下标的增长，地址是由低到高变化的
    // 3.死循环 -
    // Debug 版本下 i 的地址在 arr 之后
    // Release 版本下 i 的地址在 arr 之前 - 被优化

    // strcpy - 字符串拷贝
    {
        char arr1[] = "#############";
        char arr2[] = "bit";
        char arr3[] = "abc";
        char arr4[] = "def";
        char arr5[] = "ghi";
        char arr6[] = "jkl";
        char arr7[] = "mno";
        my_strcpy1(arr1, arr2);
        printf("%s\n", arr1);
        my_strcpy2(arr1, arr3);
        printf("%s\n", arr1);
        my_strcpy3(arr1, arr4);
        printf("%s\n", arr1);
        my_strcpy4(arr1, arr5);
        printf("%s\n", arr1);
        my_strcpy5(arr1, arr6);
        printf("%s\n", arr1);
        printf("%s\n", my_strcpy6(arr1, arr7));//返回值作为另外一个函数的参数 - 链式访问
    }

    {
        const int a = 10;
        int* p = &a;// a 的 const 和我 p 有什么关系？
        *p = 20;
        printf("%d\n", a);// 20

        //如何把地址传给 p 而禁止其修改？
        const int* pa = &a;
        // *pa = 20; 报错：Read-only variable is not assignable

        int* const pa0 = &a;
        int n = 100;
        // pa0 = &n; 报错：Cannot assign to variable 'pa0' with const-qualified type 'int *const'

        // const 放在指针变量的 * 左边时，修饰的是 *p，也就是说不能通过 p 来改变 *p(a) 的值
        // const 放在指针变量的 * 右边时，修饰的是 (指针变量)p，也就是说 p 不能被改变
        const int* const pa1 = &a;// *p(a) 不能被改变，同时 p 也不能被改变
    }

    //模拟实现 strlen
    {
        char arr[] = "abcdefg";
        int len = my_strlen(arr);
        printf("%d\n", len);
    }

    //错误类型
    // 1.编译型错误 - 语法错误(编译器报错) - 容易找到(双击问题)
    // 2.链接型错误 - 变量/函数没有声明/名字写错了 - 找到错误信息中的标识符
    // -- Use of undeclared identifier 'xxx' (无法解析的外部符号)
    // 3.运行时错误 - 结果不对 - 借助调试，逐步定位问题





    return 0;
}
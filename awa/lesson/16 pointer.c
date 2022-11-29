//
// Created by 86183 on 2022/10/18.
//
/*  指针  */

#include <stdio.h>

int* test()
{
    int a = 10;
    return &a;
}

int my_strlen(char* str)
{
    char* start = str;
    char* end = str;
    while (*end != '\0')
    {
        end ++;
    }
    return (end - start);
}

int main()
{
//一、指针是什么
    //指针(Pointer)是编程语言中的一个对象，利用地址，它的值直接指向存在电脑存储器中另一个地方的值
    //通过地址能找到所需的变量单元，可以说，地址指向该变量单元，因此将地址形象化地称为指针，意思是通过它能找到以它为地址的内存单元
    int a = 10;
    int* p = &a;//指针变量 - 指针实际上是个变量，变量中存放着地址
    //在 32 位的机器上，地址是 32 个 0 或者 1 组成的二进制序列 - 占 4 个字节
    //在 64 位的机器上，有 64 个地址线 - 指针变量占 8 个字节
    //地址能够唯一标识一块空间

//二、指针和指针类型
    printf("%lu\n", sizeof(char*));
    printf("%lu\n", sizeof(int*));
    printf("%lu\n", sizeof(short*));
    printf("%lu\n", sizeof(double*));
    //都是 8

    //都是 8 个字节，指针为什么要有类型？ - 指针类型的意义
    // 1.
    int a0 = 0x11223344;
    int* pa = &a0;
    char* pc = &a0;
    printf("%p\n", pa);
    printf("%p\n", pc);
    //打印出的地址是相同的

    *pa = 0;//能改动 4 个字节
    *pc = 0;//只能改动 1 个字节
    //指针类型决定了指针在进行解引用操作的时候，能够访问的空间的大小
    // int* p - 能够访问 4 个字节
    // char* p - 能够访问 1 个字节
    // double* p - 能够访问 8 个字节

    // 2.指针 +/- 整数
    a0 = 0x11223344;
    int* pa0 = &a0;
    char* pc0 = &a0;
    printf("%p\n", pa0);// 0xffffcc00
    printf("%p\n", pa0 + 1);// 0xffffcc04
    printf("%p\n", pc0);// 0xffffcc00
    printf("%p\n", pc0 + 1);// 0xffffcc01

    //指针类型决定了指针走一步走多远(指针的步长)
    // int* p; p + 1 --> 4 指向下一个整型(如果有)
    // char* p; p + 1 --> 1
    // double* p; p + 1 --> 8

    int arr[10] = { 0 };
    int* p_arr = arr;//数组名 - 首元素的地址
    int i = 0;
    for (i = 0; i < 10; i ++)
    {
        *(p_arr + i) = 1;
    }
    //如果换成 char*，会把数组前几个元素改成 01 01 01 01 ...

//三、野指针

    //野指针 - 指针指向的位置是不可知的(随机的，不正确的，没有明确限制的)

    // 1.未初始化
    int b;//局部变量未初始化，默认是随机值
    int* pb;//局部的指针变量，就被初始化随机值
    // *pb = 20; 将内存中的随机地址的数值变为 20，很危险

    // 2.指针越界访问
    int arr0[5] = { 0 };
    int* p_arr0 = arr0;
    int i0 = 0;
    for (i0 = 0; i0 < 12; i0 ++)
    {
        p_arr0 ++;
        //当指针指向的范围超出数组 arr0 的范围时，p 就是野指针
    }

    //注：貌似超范围再 ++ 的时候依旧会 + 4

    // 3.指针指向的内存空间释放了
    int* pd = test();
//    printf("%d\n", *pd);//实测会返回空指针(NULL) --> 最后程序停止运行
//    printf("%d\n", *pd);
    //指针指向的空间不知道被哪个程序占用了

    //如何规避野指针
    // 1.指针初始化
    //不知道初始化什么值的时候初始化空指针
    int* p1 = NULL;
    // 2.小心指针越界
    // 3.指针指向空间释放即置 NULL
    int a5 = 10;
    int* pa5 = &a5;
    *pa5 = 20;
    // ----- a 的空间已经还给操作系统
    pa5 = NULL;
    // 4.指针使用之前检查有效性
    if (pa5 != NULL)
    {
        ;
    }
//    *pa5 = 10;//同上的错误

//四、指针运算

    // 1.指针 +/- 整数
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i1 = 0;
    int sz = sizeof(arr1) / sizeof(arr1[0]);
    int* parr = arr1;
    for (i1 = 0; i1 < sz; i1 ++)
    {
        printf("%d\n", *parr);
        parr ++;
    }
    //加几就会向后移动几个指针类型的长度

    // 2.指针的关系运算(比较大小)
    float values[5];
    float* vp;
    for (vp = &values[10]; vp > &values[0];)
    {
        *--vp = 0;
    }
    //为什么数组只有 5 个数，我能取到第 11 个数的地址？
    printf("%lu\n", sizeof(values));// 20
    //因为 C 编译器不会进行越界检查，&values[10] 只是单纯的把数组首元素的地址 + 10

    // 1.
    float values0[5];
    float* vp0;
    for (vp0 = &values0[5]; vp0 > &values0[0];)
    {
        *--vp0 = 0;
    }

    // 2.
    float values1[5];
    float* vp1;
    for (vp1 = &values1[4]; vp1 > &values1[0]; vp1 --)
    {
        *vp1 = 0;
    }
    //上下两段代码比较起来，应该选择上面的代码
    //因为 C 标准规定：允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针进行比较，但是不允许与指向第一个元素之前的那个内存位置的指针进行比较

    // 3.指针 - 指针
    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* p9 = &arr2[9];
    int* p0 = &arr2[0];
    printf("%p\n", p0);// 0xffffcaf0
    printf("%p\n", p9);// 0xffffcb14
    printf("%ld\n", p9 - p0);// 9
    printf("%ld\n", p0 - p9);// -9
    // 0xffffcb14 - 0xffffcaf0 = 16 + 16 + 4 = 36
    // 36 / 4 = 9
    //指针 - 指针，得到的是两个元素之间的中间元素的个数

    char ch[5] = { 0 };
    // printf("%ld", p9 - &ch[0]);
    //报错 - 指针之间类型不兼容
    //两个指针应该指向同一块空间

    //求字符串长度 - strlen - 模拟实现 strlen 函数的功能
    // 1.计数器 2.递归 3.指针
    char ch0[] = "bit";
    int len = my_strlen(ch0);
    printf("%d\n", len);

//五、指针和数组

    int arr3[10] = { 0 };
    printf("%p\n", arr3);//首元素地址
    printf("%p\n", &arr3[0]);
    printf("%p\n", &arr3);

    printf("%p\n", arr3 + 1);// +4
    printf("%p\n", &arr3[0] + 1);// +4
    printf("%p\n", &arr3 + 1);// +40
    //数组名不是首元素地址的例外情况
    // 1.&arr - &数组名 - 数组名不是首元素的地址，而表示整个数组 --> &数组名 取出的是整个数组的地址
    // 2.sizeof(arr) - sizeof(数组名) - 数组名表示整个数组 - sizeof(数组名)计算的是整个数组的大小

    int arr4[10] = { 0 };
    int* p4 = arr4;
    int i4 = 0;
    for (i4 = 0; i4 < 10; i4 ++)
    {
        printf("%p ====== %p\n", p4 + i4, &arr4[i4]);
    }
    //说明了首元素地址 + i 和 arr[i] 的地址是一样的

    for (i4 = 0; i4 < 10; i4 ++)
    {
        *(p4 + i4) = i4;
    }
    for (i4 = 0; i4 < 10; i4 ++)
    {
        printf("%d ", *(p4 + i4));
    }
    printf("\n");

//六、二级指针

    int a6 = 10;
    int* pa6 = &a6;
    int** ppa6 = &pa6;// ppa6 就是二级指针
    int*** pppa6 = &ppa6;// pppa6 就是三级指针

    **ppa6 = 20;
    printf("%d\n", **ppa6);
    printf("%d\n", a6);

//七、指针数组 - 存放指针的数组
    int a7 = 10;
    int b7 = 20;
    int c7 = 30;
    int* pa7 = &a7;
    int* pb7 = &b7;
    int* pc7 = &c7;
    //建立数组来存放整型指针
    // int* arr7[3] = {pa7, pb7, pc7};
    int* arr7[3] = {&a7, &b7, &c7};
    int i7 = 0;
    for (i7 = 0; i7 < 3; i7 ++)
    {
        printf("%d ", *(arr7[i7]));
    }
    printf("\n");

    return 0;
}
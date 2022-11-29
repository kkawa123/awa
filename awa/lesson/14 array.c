//
// Created by 86183 on 2022/10/7.
//
#include <stdio.h>
#include <string.h>

void bubble_sort(int *arr, int sz)
{
    int i = 0;
    for (i = 0; i <= sz - 1; i++)// i 趟冒泡排序
    {
        int flag = 1;//假设这一趟要排的数据已经有序
        int j = 0;
        for (j = 0; j < sz - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = 0;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 0;//本趟排序的数据其实不完全有序
            }
        }
        if (1 == flag)
        {
            break;
        }
    }
}
//基本思想：两两相邻的元素进行比较，大的放后面，小的放前面，依此类推
// 10 9 8 7 6 5 4 3 2 1 --> 9 8 7 6 5 4 3 2 1 10  --  一趟冒泡排序
// 10 个元素 - 9 趟冒泡排序
//加入 flag 变量之后，算法被优化


int main()
{
//一维数组的创建和初始化
    //数组的创建
    //  type_t     arr_name       [const_n]
    //数组的元素类型   数组名     常量表达式，用来指定数组的大小

    int arr[10];
    char arr1[5];

    int count = 5;
    int arr2[count];// error
    //数组创建的 [] 中必须是常量

    //数组初始化 - 创建时赋值
    int arr3[10] = {1, 2, 3,};//不完全初始化 - 剩下的元素默认为 0
    char arr4[5] = "abc";// 'a' 'b' 'c' '\0' --> 0
    char arr5[5] = {'a', 98};//初始化为 a, b
    char arr6[] = "abcdefg";// [] 中没有指定大小的时候，必须进行初始化，根据初始化输入的大小自动指定
    //数组 arr6 中有 8 个元素

    printf("%d\n", sizeof(arr6));// 8
    printf("%d\n", strlen(arr6));// 7
    // strlen 求字符串的长度 - '\0' 之前的字符个数

    char arr7[] = {'a', 'b', 'c'};
    printf("%d\n", sizeof(arr7));// 3
    printf("%d\n", strlen(arr7));//随机值(没有 '\0')

    // strlen 返回无符号数

    //一维数组的使用
    char arr8[] = "abcdef";
    //打印 d
    printf("%c\n", arr8[3]);
    //打印从 a 到 d
    int i = 0;
    for(i = 0; i <= 3; i++)
    {
        printf("%c\n", arr8[i]);
    }

    //求数组中的元素个数
    int sz = sizeof(arr8) / sizeof(arr8[0]);
    //注：有 '\0'

    //一维数组在内存中的存储
    int arr9[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int sz0 = sizeof(arr9) / sizeof(arr9[0]);
    int i0 = 0;
    for(i0 = 0; i0 < sz0; i0++)
    {
        printf("&arr9[%d] = %p\n", i0, &arr9[i0]);
    }
    // &arr[0] = 0xffffcb30
    // &arr[1] = 0xffffcb34
    // &arr[2] = 0xffffcb38
    // &arr[3] = 0xffffcb3c
    // &arr[4] = 0xffffcb40
    // &arr[5] = 0xffffcb44
    // &arr[6] = 0xffffcb48
    // &arr[7] = 0xffffcb4c
    // &arr[8] = 0xffffcb50
    // &arr[9] = 0xffffcb54
    //每个都差 4 - 一个整型的大小
    //整型中的元素在内存中连续存放

//二维数组
    //二维数组的创建
    int arr10[3][4];// 3 行 4 列的二维数组
    int arr11[4][5];
    char arr12[5][6];

    //二维数组的初始化
    int arr13[3][4] = {1, 2, 3, 4, 5};//不完全初始化 - 后面的元素默认为 0
    //思考：能不能 1 2 3 放在第一行，4 5 放在第二行？
    int arr14[3][4] = {{1, 2, 3},{4, 5}};// complete
    int arr15[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    //二维数组初始化时，行可以省略，列不能省略

    //二维数组的使用
    //打印 arr14 中的所有元素
    int a = 0;
    int b = 0;
    for(a = 0; a < 3; a++)
    {
        for(b = 0; b < 4; b++)
        {
            printf("%d ", arr14[a][b]);
        }
        printf("\n");
    }
    // 1 2 3 0
    // 4 5 0 0
    // 0 0 0 0

    //二维数组在内存中的存储
    int a0 = 0;
    int b0 = 0;
    for(a0 = 0; a0 < 3; a0++)
    {
        for(b0 = 0; b0 < 4; b0++)
        {
            printf("&arr14[%d][%d] = %p\n",a0, b0, &arr14[a0][b0]);
        }
    }
//    &arr14[0][0] = 0xffffca20
//    &arr14[0][1] = 0xffffca24
//    &arr14[0][2] = 0xffffca28
//    &arr14[0][3] = 0xffffca2c
//    &arr14[1][0] = 0xffffca30
//    &arr14[1][1] = 0xffffca34
//    &arr14[1][2] = 0xffffca38
//    &arr14[1][3] = 0xffffca3c
//    &arr14[2][0] = 0xffffca40
//    &arr14[2][1] = 0xffffca44
//    &arr14[2][2] = 0xffffca48
//    &arr14[2][3] = 0xffffca4c

    //也是连续存放，与一维数组相同
    // arr[0][j] 相当于第一行数组的数组名是 arr[0]
    // arr[1][j] 相当于第二行数组的数组名是 arr[1]
    // ...

//数组作为函数参数
    //冒泡排序 - 对一个整型数组实现规律排列，如升序排列

    int arr16[] = {7, 9, 8, 5, 1, 4, 3, 6, 2, 0};
    int sz1 = sizeof(arr16) / sizeof(arr16[0]);
    bubble_sort(arr16, sz1);
    int m = 0;
    for(m = 0; m <= sz1 - 1; m++)
    {
        printf("%d ", arr16[m]);
    }
    // arr 是数组，我们对数组进行传参，实际上传递过去的是数组首元素的地址 &arr[0]
    //数组的大小不能在函数中计算

//数组名是什么？
    //数组名就是数组首元素地址 - 但有两个例外
    // 1.sizeof 内部单独放一个数组名 - 数组名表示整个数组，sizeof(数组名)计算的是整个数组的大小，单位是字节
    // 2.&数组名 - 数组名代表整个数组，取出的是整个数组的地址
    int arr17[] = {1, 2, 3, 4, 5, 6, 7};

    printf("%p\n", arr17);
    //上下等价
    printf("%p\n", &arr17[0]);

    printf("%d\n", *arr17);

    printf("%p\n", &arr17);//数组的地址

    printf("%p\n", arr17);
    printf("%p\n", arr17 + 1);//第一个元素地址 + 1 就是第二个元素地址

    printf("%p\n", &arr17[0]);
    printf("%p\n", &arr17[0] + 1);//同上

    printf("%p\n", &arr17);
    printf("%p\n", &arr17 + 1);// 0xffffc9a0 --> 0xffffc9bc  --  + 28 等于跳过整个数组
    //数组的地址和数组首元素的地址从值上看一样，但是意义不一样


    return 0;
}

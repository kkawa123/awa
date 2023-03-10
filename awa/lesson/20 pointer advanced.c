//
// Created by 86183 on 2022/11/23.
//

/* 指针进阶 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

void test1(int arr[]) //数组形式
{}

void test2(int arr[10]) //数组大小可省可不省，写错也没事
{}

void test3(int *arr) //指针形式
{}

void test4(int *arr[20]) //数组大小可以省略
{}

void test5(int* *arr) //指针形式 - 二级指针
{}

void test6(int arr[][5]) //不能省略列，只能省略行
{}

void test7(int (*arr)[5]) //指针形式 - 数组指针
{}

void test8(int* p)
{}

void test9(char* p)
{}

void test10(int** ptr)
{}

char* my_strcpy(char* dest, const char* src)
{}

int Add(int x, int y)
{
    return x + y;
}

int Sub(int x, int y)
{
    return x - y;
}

int Mul(int x, int y)
{
    return x * y;
}

int Div(int x, int y)
{
    return x / y;
}

int Xor(int x, int y)
{
    return x ^ y;
}

void Calc(int (*pf)(int, int))
{
    int x = 0;
    int y = 0;
    printf("请输入两个操作数:>");
    scanf("%d%d", &x, &y);
    printf("%d\n", pf(x, y));
}

void print1(int arr[3][5], int x, int y) //参数是数组的形式
{
    int i, j;
    for (i = 0; i < x; i ++)
    {
        for (j = 0; j < y; j ++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void print2(int (*parr)[5], int x, int y) //参数是指针的形式
{
    // parr 指的是第一个一维数组的地址，等同于二维数组的数组名
    int i, j;
    for (i = 0; i < x; i ++)
    {
        for (j = 0; j < y; j ++)
        {
            printf("%d ", *(parr[i] + j));//指针 parr[i] 指向的是二维数组第 i 行的首元素地址
            printf("%d ", parr[i][j]);
            printf("%d ", (*(parr + i))[j]);
            printf("%d ", *(*(parr + i) + j));
            //以上四种表现形式等价
        }
        printf("\n");
    }
}

void Print(const int* p, int sz)
{
    int i;
    for (i = 0; i < sz; i ++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");
}

void menu()
{
    printf("********************************\n");
    printf("******  1.add      2.sub  ******\n");
    printf("******  3.mul      4.div  ******\n");
    printf("******  5.xor      0.exit ******\n");
    printf("********************************\n");
}

void print(char* str)
{
    printf("hehe:%s\n", str);
}

void test(void (*p)(char*))
{
    printf("test\n");
    p("bit");
}

void bubble_sort(int arr[], int sz)
{
    int i;
    for (i = 0; i < sz - 1; i ++)
    {
        int j;
        int flag = 1;
        for (j = 0; j < sz - 1 - i; j ++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 0;
            }
        }
        if (flag)
        {
            break;
        }
    }
}

int cmp_int(const void* e1, const void* e2) // void* 类型的指针可以接受任意类型的地址
{                                           // void* 类型的指针不能进行解引用，不能进行加减整数的操作 - 访问几个字节不确定
    //比较两个整形值
    return *(int*) e1 - *(int*) e2;
}

int cmp_float(const void* e1, const void* e2)
{
    if (*(float*) e1 == *(float*) e2)
    {
        return 0;
    }
    else if (*(float*) e1 > *(float*) e2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

struct Stu
{
    char name[20];
    int age;
};

struct Test
{
    int Num;
    char *pcName;
    short sDate;
    char cha[2];
    short sBa[4];
}* pTest;
//假设 pTest 的值为 0x100000
//已知结构体 Test 类型的变量大小是 20 个字节

int cmp_stu_by_age(const void* e1, const void* e2)
{
    return ((struct Stu*) e1) -> age - ((struct Stu*) e2) -> age;
}

int cmp_stu_by_name(const void* e1, const void* e2)
{
    //比较名字就是比较字符串 - 不能直接用 > < = 来比较，应该用 strcmp 函数
    return strcmp(((struct Stu*) e1) -> name, ((struct Stu*) e2) -> name);
}

void Swap(char* buf1, char* buf2, int width)
{
    int i;
    for (i = 0; i < width; i ++)
    {
        char tmp = *buf1;
        *buf1 = *buf2;
        *buf2 = tmp;
        buf1 ++;
        buf2 ++;
        //思路是把多个数据拆成一个个 char，按照 width 大小依次交换
    }
}

void my_qsort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
{                                            //设计 my_qsort 不知道要比较的两个元素是什么数据类型
    int i;
    //趟数
    for (i = 0; i < sz - 1; i ++)
    {
        int j;
        //每一趟比较的对数(次数)
        for (j = 0; j < sz - 1 - i; j ++)
        {
            //两个元素的比较
            //将 base 强转成 char* 类型，再加上宽度
            if (cmp((char*) base + j * width, (char*) base + (j + 1) * width) > 0)
            {
                //交换
                Swap((char*) base + j * width, (char*) base + (j + 1) * width, width);
            }
        }
    }
}

int getNum(int num, int i)
{
    int ret = num;
    int j;
    int tmp;
    for (j = 0; j < i; j++)
    {
        num /= 10;
    }
    tmp = num;
    ret = ret * 10 + tmp;
    return ret;
}

int Sum(int num, int count, int i)
{
    for (; i < count;)
    {
        int ret = getNum(num, i);
        return Sum(ret, count, ++i) + num;
    }
    return 0;
}

int* separate_num(int num, int* arr)
{
    int i = 0;
    while (num)
    {
        arr[i] = num % 10;
        num /= 10;
        i++;
    }
    arr[6] = i;
    return arr;
}

int get_num(int* arr, int i)
{
    for (int j = 0; j < i; j++)
    {
        int tmp;
        int tmp0 = arr[j];//让其一次只乘一倍
        for (tmp = 0; tmp < i - 1; tmp++)
        {
            arr[j] *= tmp0;
        }
    }
    int sum = 0;
    for (int j = 0; j < i; j++)
    {
        sum += arr[j];
    }
    return sum;
}

int main()
{
    //一、字符指针
    {
        char arr[] = "abcdef";
        char* pc = arr;
        printf("%s\n", arr); // abcdef
        printf("%s\n", pc);// abcdef
        // %s 向后读取到 '\0'

        char *p = "abcdef";// "abcdef" 是一个常量字符串
        // p 存储的是字符串首字符的地址
        printf("%c\n", *p);// a
        printf("%s\n", p);// abcdef
        // %c 默认接受一个字面量
        // %s 默认接受指针，结束于 '\0'

        /*
        *p = 'W';
        printf("%s\n", p);
        */
        // Segmentation fault - 段错误 - 访问非法内存
        //常量字符串不能更改
    }
    {
        //一道面试题
        char arr1[] = "abcdef";
        char arr2[] = "abcdef";
        char *p1 = "abcdef";
        char *p2 = "abcdef";
        if (arr1 == arr2) //比较的是两个地址，肯定不同
        {
            printf("hehe\n");
        }
        else
        {
            printf("haha\n");
        }

        if (p1 == p2)
        {
            printf("hehe\n");//打印 hehe
        }
        else
        {
            printf("haha\n");
        }
        //类似于 Java 的串池，两个指针指向同一块空间
    }

    //二、数组指针
    //本质上是指针，指向数组，存放数组的地址 - &arr
    // &arr 代表整个数组的地址，arr 代表数组首元素的地址
    {
        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int (*p)[10] = &arr;// *p 代表这是个指针，[10] 代表这是个数组，int 表示数组里放的是整型
    }
    {
        char *arr[5];
        char *(*pa)[5] = &arr;//同理，char* 指数组的元素类型是 char*
        //指针数组的数组指针
    }
    //数组指针的用法
    {
        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int (*pa)[10] = &arr;
        int *p = arr;
        for (int i = 0; i < 10; ++i)
        {
            printf("%d ", *(p + i));
            printf("%d ", (*pa)[i]);//不加 () 会出事
            printf("%d ", *(*pa + i));
        }
        printf("\n");
        //这样用不是自讨苦吃？
    }
    //对数组名进行取地址操作是特殊的，固定得到的就是整个数组的地址，需要用数组指针来接受
    //对数组指针的解引用操作得到的是数组首元素的地址，同样还是地址
    //例：arr[3][4]  arr 表示 arr[0] 的地址，arr[0] 表示 arr[0][0] 的地址，&arr 表示整个二维数组的地址
    // *(&arr) 等同于 arr，*(&arr[0]) 等同于 arr[0]，*(&arr[0][0]) 等同于 arr[0][0]
    {
        int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
        printf("%p\n", arr);//表示第一个一维数组的地址
        printf("%p\n", arr[0]);//表示第一个一维数组中第一个元素的地址
        printf("%d\n", arr[0][0]);//表示第一个一维数组中的第一个数
        printf("%p\n", &arr);//表示二维数组的地址
        printf("%p\n", &arr[0]);//表示第一个一维数组的地址
        printf("%p\n", &arr[0][0]);//表示第一个一维数组中第一个元素的地址

        printf("%d\n", (arr + 1) == (&arr[0] + 1));// true
        printf("%d\n", (arr[0] + 1) == (&arr[0][0] + 1));// true
    }
    //那应该怎么用？- 二维数组以上才比较好用
    {
        int arr[3][5] = {{1, 2, 3, 4, 5},
                         {2, 3, 4, 5, 6},
                         {3, 4, 5, 6, 7}};
        print1(arr, 3, 5);
        print2(arr, 3, 5);
    }
    {
        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int i = 0;
        int *p = arr;
        for (i = 0; i < 10; i++)
        {
            printf("%d ", *(p + i));
            printf("%d ", *(arr + i));
            printf("%d ", arr[i]);
            printf("%d ", p[i]);
            // arr[i] == *(arr + i) == *(p + i) == p[i]
        }
    }

    //三、指针数组
    //本质上是数组，用来存放指针
    {
        int *parr[4];//存放整型指针的数组
        char *pch[5];//存放字符指针的数组
    }
    //有什么用？
    {
        int a = 10;
        int b = 20;
        int c = 30;
        int d = 40;
        int *arr[4] = {&a, &b, &c, &d};

        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
        {
            printf("%d ", *(arr[i]));
        }
        printf("\n");
        // ee，怎么可能这么用
    }
    //到底怎么用？
    {
        int arr1[] = {1, 2, 3, 4, 5};
        int arr2[] = {2, 3, 4};
        int arr3[] = {3, 4, 5, 6};
        int sz1 = sizeof(arr1) / sizeof(arr1[0]);
        int sz2 = sizeof(arr2) / sizeof(arr2[0]);
        int sz3 = sizeof(arr3) / sizeof(arr3[0]);

        int *parr[] = {arr1, arr2, arr3};//用一个一维数组控制了三个一维数组

        int sz[sizeof(parr) / sizeof(parr[0])];
        sz[0] = sz1;
        sz[1] = sz2;
        sz[2] = sz3;

        //遍历数组
        for (int i = 0; i < sizeof(parr) / sizeof(parr[0]); ++i)
        {
            int j = 0;
            for (j = 0; j < sz[i]; j++)
            {
                printf("%d ", *(parr[i] + j));
            }
            printf("\n");
        }
        //一旦各数组的元素个数不相等，遍历会很麻烦 - 不实用
    }
    {
        //小练习 - 下面的东西代表什么？
        int arr[5];// arr 是一个 5 个元素的整型数组
        int *parr1[10];// parr1 是一个 10 个元素的指针数组
        int (*parr2)[10];// parr2 是一个数组指针，数组为 int 类型，其中有 10 个整型元素
        int (*parr3[10])[5];// parr3 是一个数组，该数组有 10 个元素，每个元素是一个数组指针，该数组指针指向的数组有 5 个整型元素
    }

    //四、数组传参和指针传参
    //一维数组传参
    {
        //开头的写法可以吗？
        int arr[10] = {0};
        int *arr2[20] = {0};
        test1(arr);
        test2(arr);
        test3(arr);
        test4(arr2);
        test5(arr2);//指针数组的数组名相当于二级指针
        //都可以
    }
    //二维数组传参
    {
        //文件开头的写法正确吗？
        int arr[3][5] = {0};
        test6(arr);
        test7(arr);
        //注：不能用二级指针接受二维数组，而是用数组指针接受
    }
    //一级指针传参
    {
        int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int *p = arr;
        int sz = sizeof(arr) / sizeof(arr[0]);
        Print(p, sz);
        //简单
    }
    {
        int a = 10;
        int *p1 = &a;
        test8(&a);// ok
        test8(p1);// ok

        char ch = 'w';
        char *pc = &ch;
        test9(&ch);// ok
        test9(pc);// ok
        //结论：形参为一级指针的时候，可以接受一级指针和非指针变量的地址
    }
    //二级指针传参
    {
        int n = 10;
        int *p = &n;
        int **pp = &p;
        test10(pp);
        test10(&p);

        int *arr[10];
        test10(arr);
        //结论：形参是二级指针的时候，可以接受二级指针和一级指针的地址，还有指针数组的数组名
    }

    //五、函数指针
    //是指向函数的指针，存放了函数的地址
    {
        int a = 10;
        int b = 20;
        int ret = Add(a, b);
        printf("%d\n", ret);
        printf("%p\n", &Add);// Add 函数的地址
        printf("%p\n", Add);//也是 Add 函数的地址
        // &函数名 和 函数名 都是函数的地址

        int (*pa)(int, int) = Add;
        //前面的 int 表示函数的返回类型，后面的括号表示函数(形参)

        int ret0 = (*pa)(2, 3);
        int ret1 = (**pa)(2, 3);
        int ret2 = (***pa)(2, 3);
        printf("%d\n", ret0);
        printf("%d\n", ret1);
        printf("%d\n", ret2);
        //都是 5
        // * 是没有用的
        int ret3 = pa(2, 3);
        printf("%d\n", ret3);
        // *pa(2, 3) - error
    }
    //两段有趣的代码
    {
        // 1.
        /* (*(void (*)())0)(); */
        //把 0 强制类型转换成 void(*)() 函数指针类型 - 0 就是一个函数的地址
        //调用 0 地址处的该函数
        // 2.
        /* void (*signal0(int, void(*)(int)))(int); */
        // signal 是函数的声明，signal 函数有两个参数，一个是 int，一个是函数指针类型(指向函数的参数是 int，返回类型是 void)
        // signal 函数的返回类型也是函数指针类型 void(*)(int)，该函数指针指向的函数的参数是 int，返回类型是 void
        //相当于 void(*)(int) signal(int, void(*)(int)) (int)，但是这么写是错误的
        //读起来很费劲，能不能简洁一些？
        /*
        typedef void(* pFun_t)(int);//把函数指针类型再起一个名字叫做 pFun_t
        pFun_t signal1(int, pFun_t);//换元
        */
    }

    //六、函数指针数组
    //把几个相同类型的函数的地址放到一个函数指针数组中
    {
        int (*pa)(int, int) = Add;// Sub / Mul / Div
        //需要一个数组，这个数组可以存放 4 个函数的地址

        int (*parr[4])(int, int) = {Add, Sub, Mul, Div};
        int i;
        for (i = 0; i < 4; i++)
        {
            printf("%d\n", parr[i](2, 3));
        }
    }
    {
        //小练习 - char* my_strcpy(char* dest, const char* src);
        //写一个函数指针 pf，能够指向 my_strcpy
        //写一个函数指针数组，能够存放 4 个 my_strcpy 的指针

        char *(*pf)(char *, const char *) = my_strcpy;
        char *(*pfArr[4])(char *, const char *);
    }
    //使用场景 - 转移表
    {
        //实现一个计算器
        int input = 0;
        int x, y;
        do
        {
            menu();
            printf("请选择:>");
            scanf("%d", &input);
            switch (input)
            {
                case 1:
                    printf("请输入两个操作数:>");
                    scanf("%d%d", &x, &y);
                    printf("%d\n", Add(x, y));
                    break;
                case 2:
                    printf("请输入两个操作数:>");
                    scanf("%d%d", &x, &y);
                    printf("%d\n", Sub(x, y));
                    break;
                case 3:
                    printf("请输入两个操作数:>");
                    scanf("%d%d", &x, &y);
                    printf("%d\n", Mul(x, y));
                    break;
                case 4:
                    printf("请输入两个操作数:>");
                    scanf("%d%d", &x, &y);
                    printf("%d\n", Div(x, y));
                    break;
                case 0:
                    printf("退出\n");
                    break;
                default:
                    printf("输入错误\n");
            }
        }
        while (input);
    }
    {
        //第二种思路
        int input = 0;
        int x, y;
        int (*pfArr[])(int, int) = {0, Add, Sub, Mul, Div, Xor};
        do
        {
            menu();
            printf("请选择:>");
            scanf("%d", &input);
            if (input >= 1 && input <= 5)
            {
                printf("请输入两个操作数:>");
                scanf("%d%d", &x, &y);
                int ret = pfArr[input](x, y);
                printf("%d\n", ret);
            }
            else if (input == 0)
            {
                printf("退出\n");
            }
            else
            {
                printf("选择错误\n");
            }
        }
        while (input);
        //可以便捷地实现增加功能
    }

    //七、指向函数指针数组的指针
    {
        int arr[10] = {0};
        int (*p)[10] = &arr;//取出数组的地址

        int (*pfArr[4])(int, int);// pfArr 是一个数组 - 函数指针的数组
        int (*(*ppfArr)[4])(int, int) = &pfArr;
        // ppfArr 是一个指向函数指针数组的指针
        // ppfArr 是一个数组指针，指针指向的数组有四个元素，每个元素的类型是函数指针，该函数指针指向的函数有两个 int 类型的参数，返回值是 int
    }

    //八、回调函数
    //就是一个通过函数指针调用的函数。如果你把函数的指针(地址)作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数
    //回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应
    {
        //回顾一下之前的代码 - 能不能改进一下，不用函数指针数组？
        int input = 0;
        do {
            menu();
            printf("请选择:>");
            scanf("%d", &input);
            switch (input)
            {
                case 1:
                    Calc(Add);
                    break;
                case 2:
                    Calc(Sub);
                    break;
                case 3:
                    Calc(Mul);
                    break;
                case 4:
                    Calc(Div);
                    break;
                case 0:
                    printf("退出\n");
                    break;
                default:
                    printf("输入错误\n");
            }
        } while (input);
    }
    {
        //小案例
        test(print);
    }
    //冒泡排序 - 由于传递的数据属于 int 类型的数组，只能排序整型数组，不能排序其他类型的数组
    {
        int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
        int sz = sizeof(arr) / sizeof(arr[0]);
        bubble_sort(arr, sz);
        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    {
        struct Stu s[3] = {{"zhangsan", 20}, {"lisi", 30}, {"wangwu", 10}};
        //结构体数组
    }

    // qsort - 排序任意类型的数组
    // qsort - 库函数 - 排序 - quick sort 快速排序
    {
        int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
        int sz = sizeof(arr) / sizeof(arr[0]);
        qsort(arr, sz, sizeof(arr[0]), cmp_int);
        // qsort 函数的第一个参数是待排序数组的首元素地址
        // qsort 函数的第二个参数是待排序数组的元素个数
        // qsort 函数的第三个参数是待排序数组的每个元素的大小，单位是字节
        // qsort 函数的第四个参数是函数指针，比较两个元素所用函数的地址 - 这个函数使用者自己实现
        // qsort 函数的最后一个参数要求传输能相互比较两个元素的函数(cmp 函数)的指针，这个函数的两个参数都是 const void* (待比较两个元素的地址) - 类型不确定
        //对 cmp 函数的要求：第一个元素大于第二个元素时，返回值大于 0，等于 - 等于 0，小于 - 小于 0
        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    {
        float f[] = {9.0F, 8.0F, 7.0F, 6.0F, 5.0F, 4.0F};
        int sz = sizeof(f) / sizeof(f[0]);
        qsort(f, sz, sizeof(f[0]), cmp_float);
        for (int i = 0; i < sizeof(f) / sizeof(f[0]); ++i)
        {
            printf("%f ", f[i]);
        }
        printf("\n");
    }
    {
        struct Stu s[3] = {{"zhangsan", 20}, {"lisi", 30}, {"wangwu", 10}};
        int sz = sizeof(s) / sizeof(s[0]);
        qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
        for (int i = 0; i < sz; i ++)
        {
            printf("%d ", s[i].age);
        }
        printf("\n");

        qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
        for (int i = 0; i < sz; i ++)
        {
            printf("%s\n", s[i].name);
        }
    }
    {
        //自创 qsort - 理解原理
        //见上面的函数 my_qsort

        int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        int sz = sizeof(arr) / sizeof(arr[0]);
        //使用 my_qsort 的程序员一定知道自己排序的是什么数据
        //就应该知道如何比较待排序数组中的元素
        my_qsort(arr, sz, sizeof(arr[0]), cmp_int);
        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        struct Stu s[3] = {{"zhangsan", 20}, {"lisi", 30}, {"wangwu", 10}};
        int sz0 = sizeof(s) / sizeof(s[0]);
        my_qsort(s, sz0, sizeof(s[0]), cmp_stu_by_name);
        for (int i = 0; i < sz0; i ++)
        {
            printf("%s\n", s[i].name);
        }

        my_qsort(s, sz0, sizeof(s[0]), cmp_stu_by_age);
        for (int i = 0; i < sz0; i ++)
        {
            printf("%d ", s[i].age);
        }
        printf("\n");
    }

    //九、指针和数组面试笔试题解析
    {
        // 1.
        int a[] = {1, 2, 3, 4};
        printf("%zd\n", sizeof(a));        // 16 - 数组总大小
        printf("%zd\n", sizeof(a + 0));    // 8 - 首元素地址 + 0 -> 首元素地址大小
        printf("%zd\n", sizeof(*a));       // 4 - 首元素大小
        printf("%zd\n", sizeof(a + 1));    // 8 - 第二个元素地址大小
        printf("%zd\n", sizeof(a[1]));     // 4 - 第二个元素大小
        printf("%zd\n", sizeof(&a));       // 8 - 数组的地址大小
        printf("%zd\n", sizeof(*&a));      // 16 - 整个数组地址解引用 - 整个数组的大小
        printf("%zd\n", sizeof(&a + 1));   // 8 - 整个数组之后的地址大小
        printf("%zd\n", sizeof(&a[0]));    // 8 - 首元素地址大小
        printf("%zd\n", sizeof(&a[0] + 1));// 8 - 第二个元素地址大小
    }
    {
        // 2.
        char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
        printf("%zd\n", sizeof(arr));        // 6
        printf("%zd\n", sizeof(arr + 0));    // 8
        printf("%zd\n", sizeof(*arr));       // 1
        printf("%zd\n", sizeof(arr[1]));     // 1
        printf("%zd\n", sizeof(&arr));       // 8
        printf("%zd\n", sizeof(&arr + 1));   // 8
        printf("%zd\n", sizeof(&arr[0] + 1));// 8

        printf("%zd\n", strlen(arr));         // 随机值
        printf("%zd\n", strlen(arr + 0));     // 随机值
        /* printf("%d\n", strlen(*arr)); */   // 'a' - 97 - 访问 0x00000061 地址的内存 - 报错
        /* printf("%d\n", strlen(arr[1])); */ // 'b' - 98 - 报错
        printf("%zd\n", strlen(&arr));        // 随机值
        printf("%zd\n", strlen(&arr + 1));    // 随机值 - 6
        printf("%zd\n", strlen(&arr[0] + 1)); // 随机值 - 1
    }
    {
        // 3.
        char arr[] = "abcdef";
        printf("%zd\n", sizeof(arr));         // 7
        printf("%zd\n", sizeof(arr + 0));     // 8
        printf("%zd\n", sizeof(*arr));        // 1
        printf("%zd\n", sizeof(arr[1]));      // 1
        printf("%zd\n", sizeof(&arr));        // 8
        printf("%zd\n", sizeof(&arr + 1));    // 8
        printf("%zd\n", sizeof(&arr[0] + 1)); // 8

        printf("%zd\n", strlen(arr));          // 6
        printf("%zd\n", strlen(arr + 0));      // 6 - 首元素地址，从此开始向后
        /* printf("%zd\n", strlen(*arr)); */   // err - strlen 接受的是地址值
        /* printf("%zd\n", strlen(arr[1])); */ // err
        printf("%zd\n", strlen(&arr));         // 6
        printf("%zd\n", strlen(&arr + 1));     // 随机值
        printf("%zd\n", strlen(&arr[0] + 1));  // 5
    }
    {
        // 4.
        char *p = "abcdef";
        printf("%zd\n", sizeof(p));           // 8
        printf("%zd\n", sizeof(p + 0));       // 8
        printf("%zd\n", sizeof(*p));          // 1
        printf("%zd\n", sizeof(p[0]));        // 1   p[0] = *(p + 0)
        printf("%zd\n", sizeof(&p));          // 8
        printf("%zd\n", sizeof(&p + 1));      // 8
        printf("%zd\n", sizeof(&p[0] + 1));   // 8

        printf("%zd\n", strlen(p));           // 6
        printf("%zd\n", strlen(p + 1));       // 5
        /* printf("%zd\n", strlen(*p)); */    // err
        /* printf("%zd\n", strlen(p[0])); */  // err
        printf("%zd\n", strlen(&p));          // 随机值 - 这里取出来的是指针的地址，相当于二级指针，而 &数组名 取出来的是数组的地址，两者不能相互比较
        printf("%zd\n", strlen(&p + 1));      // 随机值
        printf("%zd\n", strlen(&p[0] + 1));   // 5
    }
    {
        // 5.二维数组
        int a[3][4] = { 0 };
        printf("%zd\n", sizeof(a));             // 48 - sizeof 单独放到数组内部 - 数组总大小
        printf("%zd\n", sizeof(a[0][0]));       // 4 - 数组第一行第一个元素
        printf("%zd\n", sizeof(a[0]));          // 16 - 二维数组第一行所有元素
        printf("%zd\n", sizeof(a[0] + 1));      // 8 - 二维数组第一行第二个元素的地址 - a[0] 是第一行的数组名，数组名此时是首元素的地址，其实就是第一行第一个元素的地址，所以 a[0] + 1 就是第一行第二个元素的地址，地址大小是 8 个字节
        printf("%zd\n", sizeof(*(a[0] + 1)));   // 4 - 二维数组第一行第二个元素
        printf("%zd\n", sizeof(a + 1));         // 8 - 二维数组第二行这个一维数组的地址 - a 是二维数组的数组名，没有 sizeof(数组名)，也没有 &数组名，所以 a 是首元素地址，而把二维数组看成多个一维数组时，二维数组的首元素是它的第一行，a 就是第一行(首元素)的地址，a + 1 就是第二行地址
        printf("%zd\n", sizeof(*(a + 1)));      // 16 - 等价于 a[1]，二维数组第二行的一维数组数组大小
        printf("%zd\n", sizeof(&a[0] + 1));     // 8 - 二维数组第二行的一维数组的地址
        printf("%zd\n", sizeof(*(&a[0] + 1)));  // 16 - 二维数组第二行的一维数组的数组大小
        printf("%zd\n", sizeof(*a));            // 16 - 二维数组第一行的一维数组的数组大小 - a 是首元素地址，*a 就是第一行，sizeof(*a) 就是计算第一行的数组大小
        printf("%zd\n", sizeof(a[3]));          // 16 - 二维数组第四行的一维数组的数组大小 - 虽然越界了，但是 sizeof 内部的表达式不参与实际运算，只看形式

        /* 总结：数组名的意义
         * 1.sizeof(数组名)，这里的数组名表示整个数组，计算的是整个数组的大小
         * 2.&数组名，这里的数组名表示整个数组，取出的是整个数组的地址
         * 3.除此之外的所有数组名都表示首元素的地址 */
    }

    //第二阶段
    {
        // 1.输出是？
        int a[5] = {1, 2, 3, 4, 5};
        int *ptr = (int *) (&a + 1);//强转，使减一的步长变成了整型
        printf("%d,%d\n", *(a + 1), *(ptr - 1));

        // 2 5

        int (*ptr0)[5] = &a + 1;
        printf("%d\n", **(ptr0 - 1));// 1
    }
    {
        // 2.输出是？
        /* 有关结构体 Test 见文件开头 */
        struct Test t;//快速跳转
        //假设 pTest 的值为 0x100000
        //已知结构体 Test 类型的变量大小是 20(+12) (?) 个字节

        printf("%zd\n", sizeof(struct Test));// 32

        pTest = (struct Test *) 0x100000;
        printf("%p\n", pTest + 0x1);
        printf("%p\n", (unsigned long) pTest + 0x1);//强转成整型
        printf("%p\n", (unsigned int*) pTest + 0x1);

        //加上 0x1 就是加 1
        // 0x(00)100020  0x(00)100001  0x(00)100004
    }
    {
        // 3.输出是？
        int a[4] = {1, 2, 3, 4};
        int *ptr1 = (int *) (&a + 1);
        int *ptr2 = (int *) ((int) a + 1);
        /* printf("%x, %x\n", ptr1[-1], *ptr2); */

        // 4 2000000
        // ptr2 先转换成整型，加一再转换成 int*，相当于指针偏移了一个字节
        // 01 /* 00 00 00 02 */ 00 00 00
        //小端存储 - 02 00 00 00 打印 2000000
        // CLion 显示段错误 awa
    }
    {
        // 4.输出是？
        int a[3][2] = {(0, 1), (2, 3), (4, 5)};
        int *p = a[0];
        printf("%d\n", p[0]);

        // 1
    }
    {
        // 5.输出是？
        int a[5][5];
        int (*p)[4];
        p = a;
        printf("%p, %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);

        // 0xfffffffffffffffc, -4
        // a 是二维数组的首元素地址，是数组指针类型 int (*)[5]
        //把 a 强行赋值给 p，那么 p 指向的也是首元素地址
        //不同的是，p 的类型是 int (*)[4]，意味着 p 代表一个 4 列的二维数组
        //那么 p[1] 指的就是首元素再加上 4 个元素(1 行)，p[4] 就是首元素加上 16 个元素
        // p[4][2] 再加上两个元素，所以实际指的是二维数组第 19 个元素
        // a[4][2] 指的是二维数组第五行第三个元素，也就是第 23 个元素
        //两指针相减得到的是元素差，即 -4，%p 打印的是 -4 的原码，也就是十六进制的 0xFFFFFFFFFFFFFFFC
    }
    {
        // 6.输出是？
        int aa[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int *ptr1 = (int *) (&aa + 1);
        int *ptr2 = (int *) (*(aa + 1));
        printf("%d, %d\n", *(ptr1 - 1), *(ptr2 - 1));

        // 10 5
    }
    {
        // 7.输出是？
        char *a[] = {"work", "at", "alibaba"};
        char **pa = a;

        pa++;
        printf("%s\n", *pa);

        // at
    }
    {
        // 8.输出是？
        char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
        char **cp[] = {c + 3, c + 2, c + 1, c};
        char ***cpp = cp;
        printf("%s\n", **++cpp);
        printf("%s\n", *--*++cpp + 3);
        printf("%s\n", *cpp[-2] + 3);
        printf("%s\n", cpp[-1][-1] + 1);

        // POINT ER ST EW
        //唯一需要注意的是，cpp 是时刻发生变化的(++ --)，而像 [-2] 这类的表达式不使其发生变化
    }

    // gets 函数 - 读取一行

    {
        //小练习 - 求和
        //求 Sn = a + aa + aaa + aaaa + aaaaa 的前五项之和，其中 a 是一个数字

        int a = 0;
        int count = 0;
        printf("请输入 a :>");
        scanf("%d", &a);
        printf("请输入求和项数:>");
        scanf("%d", &count);

        int ret = Sum(a, count, 0);
        printf("ret = %d\n", ret);

        int ret0 = 0;
        int sum = 0;
        int i;
        for (i = 0; i < count; i++)
        {
            ret0 = ret0 * 10 + a;
            sum += ret0;
        }
        printf("ret0 = %d\n", sum);
    }
    {
        //小练习 - 求水仙花数，范围 0 ~ 100000
        //水仙花数是指一个数的各位数字的 n 次方之和等于本身的数

        int count = 0;
        while (count <= 100000)
        {
            int arr[7];
            int *arr0;
            arr0 = separate_num(count, arr);
            int ret = get_num(arr0, arr[6]);
            if (ret == count)
            {
                printf("%d\n", count);
            }
            count++;
        }

        for (count = 0; count < 100000; count++)
        {
            // 1.几位数
            int n = 1;//最小是一位数
            int tmp = count;
            while (tmp /= 10)
            {
                n++;
            }

            // 2.求幂的和
            tmp = count;
            int sum = 0;
            while (tmp)
            {
                sum += pow(tmp % 10, n);
                tmp /= 10;
            }

            // 3.判断是否是自幂数
            if (sum == count)
            {
                printf("%d\n", count);
            }
        }
    }
    {
        //打印菱形
        int line;
        printf("上半部分行数:>");
        scanf("%d", &line);

        //打印上半部分
        int i;
        for (i = 0; i < line; i++)
        {
            int j;
            //打印空格
            for (j = 0; j < line - 1 - i; j++)
            {
                printf(" ");
            }
            //打印 '*'
            for (j = 0; j < 2 * i + 1; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        //打印下半部分
        for (i = 0; i < line - 1; i++)
        {
            int j;
            //打印空格
            for (j = 0; j < i + 1; j++)
            {
                printf(" ");
            }
            //打印 '*'
            for (j = 0; j < 2 * (line - i - 1) - 1; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}
//
// Created by 86183 on 2022/10/19.
//
/*  练习  */

#include <stdio.h>

int m;

void Init(int* str, int sz)
{
    int* p = str + sz;
    for (; str < p; str ++)
    {
        *str = 0;
    }
}

void Print(int* str, int sz)
{
    int* p = str + sz;
    for (; str < p; str ++)
    {
        printf("%d ", *str);
    }
    printf("\n");
}

void Reverse(int* str, int sz)
{
    int time = sz / 2;
    int* p = str + time;
    int count = 0;
    for (; str < p; str ++)
    {
        int tmp = 0;
        tmp = *str;
        *str = *(str + sz -  2 * count - 1);
        *(str + sz - 2 * count - 1) = tmp;
        count ++;
    }
}

void Reverse2(int arr[], int sz)
{
    int left = 0;
    int right = sz - 1;
    while (left <= right)
    {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        right --;
        left ++;
    }
}

int count_bit_one(unsigned int a)
{
    int count = 0;
    while (a)
    {
        if (a % 2 == 1)
        {
            count ++;
        }
        a /= 2;
    }
    return count;
}
//如果输入 -1，不就寄了？
//类型强制转换成无符号数 - 这样的话符号位的 1 被认为成有效数字 - 救回来了

int get_diff_bit(int m0, int n0)
{
    int tmp = m0 ^ n0;
    return count_bit_one(tmp);
}

void print(int x)
{
    int i = 0;
    printf("奇数位:");
    for (i = 30; i >= 0; i -= 2)
    {
        printf("%d ",(x >> i) & 1);
    }
    printf("\n");
    printf("偶数位:");
    for (i = 31; i >= 1; i -= 2)
    {
        printf("%d ", (x >> i) & 1);
    }
    printf("\n");
}

void print_multiple_form(int x)
{
    int i = 0;
    int j = 0;
    for (i = 1; i <= x; i ++)
    {
        for (j = 1; j <= i; j ++)
        {
            printf("%2d * %2d = %-3d ", i, j, i * j);
        }
        printf("\n");
    }
}
int my_strlen(char* str)
{
    if (*str != '\0')
    {
        return 1 + my_strlen(str + 1);
    }
    else
    {
        return 0;
    }
}

void reverse_string(char *arr)
{
    char tmp = arr[0];//把第一个字符拿出来
    int len = my_strlen(arr);
    arr[0] = arr[len - 1];//把最后一个字符赋给第一个字符
    arr[len - 1] = '\0';//把 '\0' 赋给最后一个字符
    if (my_strlen(arr + 1) >= 2)
    {
        reverse_string(arr + 1);
    }
    arr[len - 1] = tmp;//把第一个字符赋给最后一个字符
}

int DigitSum(int a)
{
    if (a > 0)
    {
        return ((a % 10) + DigitSum(a / 10));
    }
    else
    {
        return 0;
    }
}

double Fac(int n, int k)
{
    if (k > 0)
    {
        return n * Fac(n, k - 1);
    }
    else if (k == 0)
    {
        return 1;
    }
    else
    {
        return 1.0 / Fac(n, -k) ;
    }
}

int main()
{
    //创建一个整型数组，完成对数组的操作
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = sizeof(arr) / sizeof(arr[0]);

    Reverse(arr, sz);//实现对数组元素的逆置
    Print(arr, sz);
    Reverse2(arr, sz);
    Print(arr, sz);//打印数组中的每个元素

    Init(arr, sz);//初始化数组为 0
    Print(arr, sz);

    //将数组 a 中的内容和数组 b 中的内容进行交换
    int a[5] = {1, 3, 5, 7, 9};
    int b[5] = {2, 4, 6, 8, 10};
    int i = 0;
    for (i = 0; i < 5; i ++)
    {
        int tmp = 0;
        tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
    Print(a, 5);
    Print(b, 5);

    //判断输出
    m --;// m = -1
    if (i > sizeof(i)) // sizeof() - 计算变量/类型所占内存的大小 >= 0，默认为无符号数
        // i 发生隐式转换 - 转换成 unsigned int 类型 - 补码很大
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }
    //输出 >

    //判断
    int a0 = 5;
    int b0, c0;
    c0 = ++ a0;// c0 = 6, a0 = 6
    c0 += 1;// c0 = 7
    b0 = ++ c0, c0 ++, ++ a0, a0 ++;// c0 = 9, a0 = 8, b0 = 7
    //注意：赋值的优先级高于逗号表达式，++ c0 被赋给 b0
    b0 += a0 ++ + c0;// a0 = 9, c0 = 8, b0 = 23
    printf("a = %d b = %d c = %d\n", a0, b0, c0);

    //写一个函数求 a 的二进制(补码)表示中有几个 1
    int a1 = 0;
    scanf("%d", &a1);
    int count = count_bit_one(a1);
    printf("count = %d\n", count);

    //求两个数中二进制位不同的个数
    // 1.一个一个比
    // 2.异或一下得到不同位的 1，再求 1 的个数
    int m0 = 0;
    int n0 = 0;
    scanf("%d %d", &m0, &n0);
    int count0 = get_diff_bit(m0, n0);
    printf("%d\n", count0);

    //打印一个整数二进制的奇数位和偶数位
    int x = 0;
    scanf("%d", &x);
    print(x);

    //实现一个函数，打印乘法口诀表 - 输入 9 打印 9 * 9，输入 12 打印 12 * 12
    int row = 0;
    scanf("%d", &row);
    print_multiple_form(row);

    //把两个整形有序数组化成一个整形有序数组
    int s[10] = {0, 1, 3, 8, 19, 56, 144, 328, 795, 2160};
    int t[10] = {1, 4, 8, 16, 35, 75, 200, 520, 1629, 3165};
    int w[20] = { 0 };

    int time_w = 0;
    int time_s = 0;
    int time_t = 0;
    while(time_w <= 19)
    {
        if (time_s == 10)
        {
            for (;time_w <= 19; time_w ++, time_t ++)
            {
                w[time_w] = t[time_t];
            }
            break;
        }
        if (time_t == 10)
        {
            for (;time_w <= 19; time_w ++, time_s ++)
            {
                w[time_w] = s[time_s];
            }
            break;
        }
        if (s[time_s] > t[time_t])
        {
            w[time_w] = t[time_t];
            time_t ++;
        }
        else
        {
            w[time_w] = s[time_s];
            time_s ++;
        }
        time_w ++;
    }
    Print(w, 20);

    //编写一个函数 reverse_string(char* string)，将参数字符串中的字符反向排列(递归实现)
    //附加条件：不能使用 C 的库函数
    char ch[] = "hello bit";
    reverse_string(ch);
    printf("%s\n", ch);

    //计算一个数的每位之和(递归实现)
    int l = 0;
    scanf("%d", &l);
    int sum = DigitSum(l);
    printf("%d\n", sum);

    //递归实现 n 的 k 次方
    int num = 0;
    int k = 0;
    scanf("%d %d", &num, &k);
    double ret = Fac(num, k);
    printf("%lf\n", ret);

    return 0;
}
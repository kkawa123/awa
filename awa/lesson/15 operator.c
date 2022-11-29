//
// Created by 86183 on 2022/10/12.
//
#include <stdio.h>

int get_val()
{
    return 0;
}

void count_val(int x)
{
    ;
}

int get_max(int x, int y) //这里的括号不是函数调用操作符，是语法规则
{
    return (x > y ? x : y);
}

int fun()
{
    static int count = 1;
    return ++count;
}

// struct 相当于一种数据类型，能够创建变量
//学生 - 创建一种结构体类型 - struct Stu
struct Stu
{
    //成员变量
    char name[20];
    int age;
    char id[20];
};

int main()
{
//除法 / 取模操作符

    int a = 5 / 2;//商 2
    int b = 5 % 2;//余 1
    printf("%d\n", a);
    printf("%d\n", b);
    //除号两端的数字都是除法 --> 整数除法
    //除号两端的数字至少有一个是浮点数 --> 浮点数除法
    //其他算术操作符同理
    double c = 5.0 / 2;
    printf("%.1lf\n", c);
    //对于取模来说，两端的数字必须为整型

//移位操作符

    // >> - 右移(二进制位)操作符
    // 1.算术右移
    //右边丢弃，左边补原符号位
    // 2.逻辑右移
    //右边丢弃，左边补 0
    int e = -1;    // 10000000000000000000000000000001 - 原码
                   // 11111111111111111111111111111110 - 反码
                   // 11111111111111111111111111111111 - 补码 - 右移一位结果不变
    int f = e >> 1;// 10000000000000000000000000000001 - 原码
    printf("%d\n", f);// -1
    int g = 16;
    int h = g >> 1;
    printf("%d\n", h);// 8
    int i = g >> 2;
    printf("%d\n", i);// 4
    //右移一位相当于除 2 (同 '/')

    // << - 左移(二进制位)操作符
    //左边丢弃，右边补 0
    int j = 5;     // 00000000000000000000000000000101
    int k = j << 1;// 00000000000000000000000000001010
    printf("%d\n", k);// 10
    //左移一位相当于乘 2

    //对于移位运算符，不要移动负数位
    //只能移动整型，因为浮点数的存储完全不同，一些操作符同理

//位操作符
    //注：计算的时候要按照整型的补码进行计算
    // & - 按(二进制)位与
    int l = 3;    // 00000000000000000000000000000011
    int m = 5;    // 00000000000000000000000000000101
    int n = l & m;// 00000000000000000000000000000001
    printf("%d\n", n);// 1

    // | - 按(二进制)位或
    int o = 3;    // 00000000000000000000000000000011
    int p = 5;    // 00000000000000000000000000000101
    int q = o | p;// 00000000000000000000000000000111
    printf("%d\n", q);// 7

    // ^ - 按(二进制)位异或 - 对应的二进制位相同为 0，相异为 1
    int r = 3;    // 00000000000000000000000000000011
    int s = 5;    // 00000000000000000000000000000101
    int t = r ^ s;// 00000000000000000000000000000110
    printf("%d\n", t);// 6

    //不能创建临时变量，实现两个 int 整型的交换
    // 1.加减法 - 可能会溢出
    int w = 3;
    int x = 5;
    w = w + x;// 8
    x = w - x;// 3
    w = w - x;// 5
    printf("%d\n", w);// 5
    printf("%d\n", x);// 3
    // 2.异或法 - 对同一个数异或两次等于它本身 - 执行效率低，可读性低
    int u = 3;// 00000000000000000000000000000011
    int v = 5;// 00000000000000000000000000000101
    u = u ^ v;// 00000000000000000000000000000110
    v = u ^ v;// 00000000000000000000000000000011
    u = u ^ v;// 00000000000000000000000000000101
    printf("%d\n", u);// 5
    printf("%d\n", v);// 3

    //编写代码实现:求一个整数存储在内存中的二进制中 1 的个数
    // 1.我的想法
    int y = 1;// 00000000000000000000000000000001
    int z = 0;
    scanf("%d", &z);
    int aa = 0;
    int count = 0;
    if (z >= 0)
    {
        while (z > 0)
        {
            aa = y & z;
            if (aa == 1)
            {
                count ++;
            }
            z >>= 1;
        }
    }
    else
    {
        int time = 0;
        while (time < 32)
        {
            aa = y & z;
            if (aa == 1)
            {
                count ++;
            }
            z >>= 1;
            time ++;
        }
    }
    printf("二进制中有 %d 个 1\n", count);

    // 2.老师的方法 - 1
    int num = 0;
    int count0 = 0;
    scanf("%d", &num);
    //统计 num 的补码中有几个 1 - 求二进制 - 除 2  余 2 ; 除 2 ...
    while (num)
    {
        if (num % 2 == 1)
        {
            count0 ++;
        }
        num /= 2;
    }
    printf("%d\n", count0);
    //只能计算正整数，代码不完全

    // 3.老师的方法 - 2
    scanf("%d", &num);
    int count1 = 0;
    int i0 = 0;
    for (i0 = 0; i0 < 32; i0 ++)
    {
        if (1 == ((num >> i0) & 1))
        {
            count1 ++;
        }
    }
    printf("%d\n", count1);
    //缺点 - 代码的执行效率低，要循环 32 次

    // 4.老师的方法 - 3
    int num0 = 0;
    scanf("%d", &num0);
    int i1 = 0;
    int count2 = 0;
    while (num0)
    {
        count2 ++;
        num0 = num0 & (num0 - 1);//减少一个二进制位的 1
    }
    printf("%d\n", count2);
    //经典的好题

//赋值操作符

    // '='
    int weight = 120;
    weight = 89;
    int a1 = 10;
    int a2 = 0;
    int a3 = 20;
    a1 = a2 = a3 + 1;//连续赋值

    //复合赋值符
    int ab = 10;

    ab = ab + 2;
    ab += 2;//复合赋值符

    ab = ab >> 1;
    ab >>= 1;

    ab = ab & 1;
    ab &= 1;

//单目操作符 - 只有一个操作数

    // '+' - a + b 双目操作符

    // ! 逻辑反操作 - 真变成假，假变成真
    int ac = 10;
    int ad = 0;
    printf("%d\n", !ac);// 0
    printf("%d\n", !ad);// 1
    if (!ad) // a 为假，打印 hehe
    {
        printf("hehe\n");
    }
    if (ad) // a 为真，打印 hehe
    {
        printf("hehe\n");
    }

    // - 负值
    int ae = -5;
    ae = -ae;

    // + 正值
    // & 取地址
    // * 解引用操作符
    int af = 10;
    int * p_af = &af;// p - 指针变量
    *p_af = 20;//解引用操作符

    // sizeof 操作符的类型长度
    int ag = 10;
    char ah = 'c';
    char * p_ah = &ah;
    int arr[10] = { 0 };
    // sizeof 计算变量所占内存空间的大小，单位是字节
    printf("%d\n", (unsigned int)sizeof(ag));
    printf("%d\n", (unsigned int)sizeof(int));// 4

    printf("%d\n", (unsigned int)sizeof(ah));
    printf("%d\n", (unsigned int)sizeof(char));// 1

    printf("%d\n", (unsigned int)sizeof(p_ah));
    printf("%d\n", (unsigned int)sizeof(char*));// 8 - 指针的大小在 32 位的系统上是 4

    printf("%d\n", (unsigned int)sizeof(arr));
    printf("%d\n", (unsigned int)sizeof(int [10]));// 40 - 数组的类型就是数组定义去掉数组名
    // sizeof 后面如果是变量，括号可以省略；如果是变量，括号不能省略
    short ai = 0;
    int aj = 10;
    printf("%d\n", sizeof(ai = aj + 5));// 2
    //把 aj 和 5 相加放到 ai 里，变量所占空间由 ai 决定(也就是 2)
    printf("%d\n", ai);// 0
    // sizeof 内部的表达式不参与运算

    // ~ 对一个数的二进制按位取反
    int ak = 0;
    printf("%d\n", ~ak);// -1

    int al = 11;// 00000000000000000000000000001011 --> 00000000000000000000000000001111
    int am = al | 1 << 2;
    printf("%d\n", am);// 15
    al = am & (~(1 << 2));// 00000000000000000000000000001111 --> 00000000000000000000000000001011
    printf("%d\n", al);// 11

    // -- 前置、后置 --
    // ++ 前置、后置 ++
    int an = 10;
    printf("%d\n", ++an);//前置 ++，先 ++，后使用 - 11
    printf("%d\n", an++);//后置 ++，先使用，后 ++ - 11
    printf("%d\n", an);// 12

    // (类型) 强制类型转换
    int ao = (int)3.14;

//关系操作符

    // > >= < <= == !=
    //相等要用 == 而不是 =

//逻辑操作符

    // &&　逻辑与
    // ||　逻辑或
    int ap = 3;
    int aq = 5;
    int ar = ap && aq;//两个都为真 - 1  其余 - 0
    int as = ap || aq;//两个都为假 - 0  其余 - 1
    printf("%d\n", ar);// 1
    printf("%d\n", as);// 1

    int at = 0, au = 0, av = 2, aw = 3, ax = 4;
    at = au++ && ++av && ax++;
    printf("au = %d\nav = %d\naw = %d\nax = %d\n", au, av, aw, ax);
    // 1 2 3 4
    // && 的用法:左边 au++ 值为 0，后面的表达式不再计算(都没加)

    int ay = 0, az = 1, ba = 2, bb = 3, bc = 4;
    ay = az++ || ++ba || bc++;
    printf("az = %d\nba = %d\nbb = %d\nbc = %d\n", az, ba, bb, bc);
    // 2 2 3 4
    // || 的用法:左边 az++ 值为 1，后面的表达式不再计算(都没加)

//条件操作符(三目操作符)

    // exp1 : exp2 ? exp3
    // exp1 为真，exp2 将被计算并成为整个表达式的结果
    // exp1 为假，exp3 将被计算并成为整个表达式的结果
    int bd = 0;
    int be = 0;
    be = (bd > 5 ? 3 : -3);

    int bf = 10;
    int bg = 20;
    int max = 0;
    max = (bf > bg ? bf : bg);

//逗号表达式

    // exp1, exp2, exp3, ... , expN
    //逗号表达式，就是用逗号隔开的多个表达式，从左向右依次执行，整个表达式的结果是最后一个表达式的结果
    int bh = 1;
    int bi = 2;
    int bj = (bh > bi, bh = bi + 10, a, bi = bh + 1);
    printf("%d\n", bj);// 13

    int d = 1;
    if (bh = bi + 1, bj = bh / 2, d > 0)
    {
        ;
    }
    //真正起到判断作用的是 d > 0, 但是前面两个式子也要算

    a = get_val();
    count_val(a);
    while (a > 0)
    {
        //业务处理
        a = get_val();
        count_val(a);
    }

    while (a = get_val(), count_val(a), a > 0)
    {
        ;//业务处理
    }
    //两段代码等价 - 下面的代码简洁但可读性差

//下标引用操作符，函数调用操作符，结构成员访问操作符

    //下标引用
    int bk[10] = { 0 };
    bk[4] = 10;
    // [] 的操作数有两个，第一个是数组名，第二个是索引值(下标)

    //函数调用
    int bl = 10;
    int bm = 20;
    int max0 = get_max(bl, bm);
    //调用函数时候的 () 就是函数调用操作符
    printf("max = %d\n", max0);
    //操作数是 1(函数名) + x(传参个数)

    //结构成员访问操作符
    //使用 struct Stu 类型创建了一个学生对象 s1，并初始化
    struct Stu s1 = {"张三", 20, "2022090901006"};
    printf("%s\n", s1.name);
    printf("%d\n", s1.age);
    printf("%s\n", s1.id);
    //结构体变量.成员名

    struct Stu *ps = &s1;
    printf("%s\n", (*ps).name);
    printf("%d\n", (*ps).age);
    printf("%s\n", ps -> name);
    printf("%d\n", ps -> age);//不用解引用
    //结构体指针 -> 成员名

//表达式求值

  //隐式类型转换
    // 1.整型提升
    // C 的整型算术运算总是至少以缺省整型类型的精度来进行的
    //为了获得这个精度，表达式中的字符和短整型操作数在使用之前被转换为普通整形，这种转换称为整型提升

    char bn = 3;
    // 0000 0011 - 发生截断
    char bo = 127;
    // 0111 1111 - 发生截断
    char bp;
    bp = bn + bo;
    // bn 和 bo 如何相加？
    // bn，bo --> 整型提升 - 按照变量的数据类型的符号位来提升的
    // 符号位默认是(八位中的)最高位 - 0
    // bn - 00000000000000000000000000000011
    // bo - 00000000000000000000000001111111
    // bp - 00000000000000000000000010000010
    // bp --> 截断，拿到 8 个比特位
    // bp - 10000010
    //由于 printf 中打印的数据类型是 %d，发生隐式类型转换(整型提升)
    // bp - 11111111111111111111111110000010 - 补码
    // bp 的原码是 10000000000000000000000001111110 - -126
    printf("%d\n", bp);// -126

    /* 无符号数整型提升直接补 0 */
    //对电脑来说，单个字节的加法难以实现，所以需要整型提升来补成 4 个字节

    char a0 = 0xb6;// 10110110
    short b0 = 0xb600;
    int c0 = 0xb6000000;
    if (a0 == 0xb6) //比较的时候会整型提升 - 在前面补 1 - 结果不同
    {
        printf("a");
    }
    if (b0 == 0xb600)
    {
        printf("b");
    }
    if (c0 == 0xb6000000)
    {
        printf("c\n");
    }

    char bq = 1;
    printf("%lu\n", sizeof(bq));// 1
    printf("%lu\n", sizeof(+bq));// 4 - 进行运算 - 整型提升
    printf("%lu\n", sizeof(!bq));// 4
    //只要 bq 参与表达式运算就会发生整型提升

    // 2.算术转换
    // long double             ^    越
    // double                  |
    // float                   |    来
    // unsigned long int       |
    // long int                |    越
    // unsigned int            |
    // int                     |    大

    //如果某个操作符的各个操作数属于不同的类型，就会把上述排名较低的类型自动转化为排名较高的类型

  //操作符的属性
    //复杂表达式的求值有三个影响的因素
    // 1.操作符的优先级
    int br = 10;
    int bs = 20;
    int bt = bs + br * 3;//先乘后加
    printf("%d\n", bt);
    // 2.操作符的结合性(优先级相同的情况下考虑)
    int bu = bs + bt + 3;//算术运算符具有左结合性
    // 3.是否控制求值顺序

    //关于三点的详细信息见文件 test 28.c

    //问题表达式
    // 1.
    int bv = a * b + c * d + e * f;
    // * 的优先级比 + 高只能保证 * 的计算比 + 早，但是优先级并不能决定第三个 * 比第一个 + 早执行
    //计算路径 1
    // a * b, c * d
    // a * b + c * d
    // e * f
    // a * b + c * d + e * f
    //计算路径 2
    // a * b, c * d, e * f
    // a * b + c * d + e * f

    //假设 a, b, c都是表达式
    //既然无法保证计算路径的唯一性，则先计算哪个表达式不确定，如果前面/后面计算的表达式影响式子中变量的值，则最后计算的结果不确定
    //代码有问题

    // 2.
    int bw = 5;
    int bx = bw + --bw;
    printf("%d\n", bx);
    // -- 的优先级高，只能保证 -- 比 + 先算，但是 + 左面的值不知道是什么时候准备好的

    // 3.非法表达式
    int by = 10;
    by = by-- - --by * (by = -3) * by++ + ++by;
    printf("%d\n", by);
    //不同编译器的计算值不同

    // 4.
    int answer;
    answer = fun() - fun() * fun();
    printf("%d\n", answer);
    //无法确定哪个 fun 函数先调用，结果不确定

    // 5.
    int bz = 1;
    int ca = (++bz) + (++bz) + (++bz);
    printf("ca = %d\n", ca);
    //结果不确定

    //总结：我们写出的表达式如果不能通过操作符的属性确定唯一的计算路径，那么写出的代码就是有问题的


    return 0;
}
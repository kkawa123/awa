//
// Created by 86183 on 2022/9/8.
//
#include <stdio.h>
#include <string.h>

int main()
{
//字符串 - 双引号引起的一串字符
    "abcd";
    "hello bit";
    "";//空字符串
    char arr1[] = "abc";//定义字符数组
    //"abc" - 'a' 'b' 'c' '\0' - '\0' 是字符串的结束标志，值为 0
    // '\0' - 0
    // 'a' - 97
    // 'A' - 65
    // ASCII 编码
    char arr2[] = { 'a', 'b', 'c', '\0'};
    printf("%s\n", arr1);
    printf("%s\n", arr2);
    char arr3[] = { 'a', 'b', 'c'};
    printf("%d\n", strlen(arr1));// strlen - string length - 计算字符串长度
    printf("%d\n", strlen(arr3));//打印随机数

//转义字符 - 转变原来的意思
    printf("abc\n");// \n 转义字符，换行
    printf("C:\\test\\32\\test.c\n");// \t 转义字符，水平制表符（缩进）
    // "\\" 可以防止"\"被解释成转义序列符
    printf("%c\n", '\'');//转义'
    printf("%s\n", "\"");//转义"
    printf("%d\n", strlen("C:\test\32\test.c"));// 13
    // \32 是两个八进制数字 0-7
    // 32 作为 8 进制代表的那个十进制数字作为ASCII码值对应的字符
    // 3 * 8^1 + 2 * 8^0 = 26 --> 作为ASCII码值
    printf("%c\n", '\32');
    printf("%c\n", '\132');// Z
    printf("%c\n", '\x61');// a
    // \x61 是两个十六进制数字 --> 97 --> a

//注释
    /*
    这是注释awa
    不支持嵌套，别用
    */

    //这也是注释
    //快捷键 CTRL + K + C/U

    return 0;
}
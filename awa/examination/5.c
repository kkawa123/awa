//
// Created by 86183 on 2022/10/28.
//

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE];
int top = 0;

void stack_overflow(void)
{
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(char ch)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = ch;
}

int main(void)
{
    char ch, temp;
    int n = 0;
    int i;
    printf("请输入括号串的个数:>");
    int time;
    scanf("%d", &time);
    getchar();//读取 '\n'
    char a[time];
    for (i = 0; i < time; i ++)
    {
        n = 0;
        top = 0;//校正 top
        while ((ch = getchar()) != '\n')
        {
            if (top < 0)
            {
                n = 1;
                while ((ch = getchar()) != '\n');//将缓冲池读取空(可能剩下 ')' '}')
                break;
            }
            if (ch == '(' || ch == '{')
                push(ch); //推进去
            else if (ch == ')' || ch == '}')
            {
                temp = contents[--top]; //把上一个推给temp
                if (ch == ')' && temp != '(') //检验
                {
                    n = 1;
                    //printf("ch:%c   temp:%c\n", ch, temp);
                }
                else if (ch == '}' && temp != '{')
                    n = 1;
            }
        }
        if (contents[--top] != '\0')
            n = 1;
        if (n == 1)
            a[i] = 'N';
        else
            a[i] = 'Y';
    }
    for (i = 0; i < time; i ++)
    {
        printf("%c\n", a[i]);
    }


    return 0;
}
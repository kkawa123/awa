//
// Created by 86183 on 2022/11/10.
//
#include <stdio.h>

void Reverse(char* pch, int count)
{
    int left = 0;
    int right = count - 1;
    while (left < right)
    {
        char tmp = pch[left];
        pch[left] = pch[right];
        pch[right] = tmp;
        left ++;
        right --;
    }
}

int main()
{
    char chars[100];
    int ch;
    int count = 0;
    int i = 0;
    printf("Enter a massage:");
    while ((ch = getchar()) != '\n')
    {
        count ++;
        chars[i] = (char) ch;
        i ++;
    }
    Reverse(chars, count);
    printf("Reversal is:");
    for (i = 0; i < count; i ++)
    {
        printf("%c", chars[i]);
    }

    return 0;
}
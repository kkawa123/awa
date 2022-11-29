//
// Created by 86183 on 2022/9/17.
//
#include <stdio.h>

int main()
{
    int ch = 0;
    while ((ch = getchar()) != '\n')
    {
        if ((ch >= '0' && ch <= '9') || ch == '-')
            putchar(ch);
        else
            switch (ch)
            {
                case 'A':
                case 'B':
                case 'C':
                {
                    printf("2");
                    break;
                }
                case 'D':
                case 'E':
                case 'F':
                {
                    printf("3");
                    break;
                }
                case 'G':
                case 'H':
                case 'I':
                {
                    printf("4");
                    break;
                }
                case 'J':
                case 'K':
                case 'L':
                {
                    printf("5");
                    break;
                }
                case 'M':
                case 'N':
                case 'O':
                {
                    printf("6");
                    break;
                }
                case 'P':
                case 'Q':
                case 'R':
                case 'S':
                {
                    printf("7");
                    break;
                }
                case 'T':
                case 'U':
                case 'V':
                {
                    printf("8");
                    break;
                }
                case 'W':
                case 'X':
                case 'Y':
                case 'Z':
                {
                    printf("9");
                    break;
                }
                default:
                    ;
            }
    }
    return 0;
}

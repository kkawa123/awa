//
// Created by 86183 on 2022/10/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned int) time(NULL));
    char arr[10][10] = {0};
    int i = 0;
    int j = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            arr[i][j] = '.';
        }
    }
    i = 0, j = 0;
    int count = 0;
    char ch = 65;
    arr[i][j] = ch;
    while (ch < 90)
    {
        if ((arr[i - 1][j] != '.') && (arr[i][j - 1] != '.') && (arr[i][j + 1] != '.') && (arr[i + 1][j] != '.'))
        {
            break;
        }
        int x = rand() % 4;
        switch(x)
        {
            case 0:
                if (arr[i][j - 1] == '.')
                {
                    j -= 1;
                    if (j == -1)
                    {
                        j += 1;
                        break;
                    }
                    ch ++;
                    arr[i][j] = ch;
                    break;
                }
                else
                {
                    break;
                }
            case 1:
                if (arr[i - 1][j] == '.')
                {
                    i -= 1;
                    if (i == -1)
                    {
                        i += 1;
                        break;
                    }
                    ch ++;
                    arr[i][j] = ch;
                    break;
                }
                else
                {
                    break;
                }
            case 2:
                if (arr[i][j + 1] == '.')
                {
                    j += 1;
                    if (j == 10)
                    {
                        j -= 1;
                        break;
                    }
                    ch ++;
                    arr[i][j] = ch;
                    break;
                }
                else
                {
                    break;
                }
            case 3:
                if (arr[i + 1][j] == '.')
                {
                    i += 1;
                    if (i == 10)
                    {
                        i -= 1;
                        break;
                    }
                    ch ++;
                    arr[i][j] = ch;
                    break;
                }
                else
                {
                    break;
                }
            default:
                break;
        }
        count ++;
        if (count >= 500)
        {
            break;
        }
    }
    for (i = 0; i < 10; i ++)
    {
        for (j = 0; j < 10; j ++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
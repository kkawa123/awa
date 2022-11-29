//
// Created by 86183 on 2022/10/14.
//
#include <stdio.h>

int main()
{
    int arr[50] = { 0 };
    int ch = 0;
    int i = 0;
    while((ch = getchar()) != '\n')
    {
        arr[i] = ch;
        i++;
    }
    int num = 0;
    scanf("%d", &num);
    int a = 0;
    for (a = 0; a < i; a++)
    {
        if (arr[a] >= 65 && arr[a] <= 90)
        {
            if (arr[a] + num <= 90)
            {
                arr[a] += num;
            }
            else
            {
                arr[a] -= 26;
                arr[a] += num;
            }
        }
        else
        {
            if ((arr[a] == 32) || (arr[a] == 44) || (arr[a] == 46))
            {
                continue;
            }
            else
            {
                if (arr[a] + num <= 122)
                {
                    arr[a] += num;
                }
                else
                {
                    arr[a] -= 26;
                    arr[a] += num;
                }
            }
        }
    }
    for (a = 0; a < i; a++)
    {
        printf("%c", arr[a]);
    }
    return 0;
}

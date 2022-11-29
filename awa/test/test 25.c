//
// Created by 86183 on 2022/10/12.
//
#include <stdio.h>

int main()
{
    int ch = 0;
    int arr[100] = { 0 };
    int show[100] = { 0 };
    int i = 0;
    while ((ch = getchar()) != '\n')
    {
        arr[i] = ch - '0';
        i ++;
    }
    int sz = i;

    int a = 0;
    for (a = 0; a <= 9; a ++)
    {
        for (i = 0; i < sz; i ++)
        {
            if (arr[i] == a)
            {
                show[a] ++;
            }
        }
    }
    printf("Digit      :0 1 2 3 4 5 6 7 8 9\n");
    printf("Occurrences:");
    for (i = 0; i < 10; i ++)
    {
        printf("%d ", show[i]);
    }
    return 0;
}
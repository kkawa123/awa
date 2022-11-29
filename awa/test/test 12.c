//
// Created by 86183 on 2022/9/11.
//

#include <stdio.h>

int main()
{
    int i = 0;
    while (i <= 100)
    {
        if (i % 2 == 1)
            printf("%d\n", i);
        i++;
    }
    return 0;
}
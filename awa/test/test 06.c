//
// Created by 86183 on 2022/9/11.
//
#include <stdio.h>

int main()
{
    int mm = 0;
    int dd = 0;
    int yyyy = 0;

    scanf("%d / %d / %d", &mm, &dd, &yyyy);
    if (mm < 10)
        if (dd < 10)
            printf("You entered the date %d0%d0%d\n", yyyy, mm, dd);
        else
            printf("You entered the date %d0%d%d\n", yyyy, mm, dd);
    else
        if (dd < 10)
            printf("You entered the date %d%d0%d\n", yyyy, mm, dd);
        else
            printf("You entered the date %d%d%d\n", yyyy, mm, dd);
    return 0;
}
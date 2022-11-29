//
// Created by 86183 on 2022/9/14.
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("chcp 65001");
    int a, b, i = 1;
    printf("Enter number of days in month:");

    scanf("%d", &a);
    printf("Enter starting day of the week(1=Sun, 7=Sat):");
    scanf("%d", &b);

    printf("  日   一   二  三  四  五   六\n");
    switch(b)
    {
        case 1:
            while (i <= a)
            {
                if (i == 8 || i == 15 || i == 22 || i == 29)
                {
                    printf("\n");
                }
                printf("%4d", i);
                i++;
            }
        case 2:
            printf("    ");
            while (i <= a)
            {
                if (i == 7 || i == 14 || i == 21 || i == 28)
                {
                    printf("\n");
                }
                printf("%4d", i);
                i++;
            }
        case 3:
            printf("\t");
            while (i <= a)
            {
                if (i == 6 || i == 13 || i == 20 || i == 27)
                {
                    printf("\n");
                }
                printf("%4d", i);
                i++;
            }
        case 4:
            printf("\t    ");
            while (i <= a)
            {
                if (i == 5 || i == 12 || i == 19 || i == 26)
                {
                    printf("\n");
                }
                printf("%4d", i);
                i++;
            }
        case 5:
            printf("\t\t");
            while (i <= a)
            {
                if (i == 4 || i == 11 || i == 18 || i == 25)
                {
                    printf("\n");
                }
                printf("%4d", i);
                i++;
            }
        case 6:
            printf("\t\t    ");
            while (i <= a)
            {
                if (i == 3 || i == 10 || i == 17 || i == 24 || i == 31)
                {
                    printf("\n");
                }
                printf("%4d", i);
                i++;
            }
        case 7:
            printf("\t\t\t");
            while (i <= a)
            {
                if (i == 2 || i == 9 || i == 16 || i == 23 || i == 30)
                {
                    printf("\n");
                }
                printf("%4d", i);
                i++;
            }

    }

    return 0;
}
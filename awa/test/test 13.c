//
// Created by 86183 on 2022/9/14.
//
#include <stdio.h>


int main()
{
    int grade = 0;
    scanf("%d", &grade);
    if (grade >= 0 && grade <= 100)
    {
        grade /= 10;
        switch (grade)
        {
            case 10:
            case 9:
                printf("Letter grade: A");
                break;
            case 8:
                printf("Letter grade: B");
                break;
            case 7:
                printf("Letter grade: C");
                break;
            case 6:
                printf("Letter grade: D");
                break;
            case 5:
            case 4:
            case 3:
            case 2:
            case 1:
            case 0:
                printf("Letter grade: F");
        }
    }
    else
        printf("Error, grade must be between 0 and 100.");
    return 0;
}
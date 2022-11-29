//
// Created by 86183 on 2022/9/14.
//
#include<stdio.h>
#include <stdlib.h>
int main()
{
    system("chcp 65001");
    int days,start,i=1,j=1;
    printf("Enter number of days in month: ");
    scanf("%d",&days);
    printf("Enter starting day of the week(1=Sun, 7=Sat):");
    scanf("%d",&start);
    printf("日 一 二 三 四 五 六\n");
    while(j<start){
        printf("  ");
        j++;
    }
    while(i<=days){
        if(j%7){
            printf("%2d",i);
        }
        else{
            printf("%2d\n",i);
        }
        i++;
        j++;
    }
    return 0;
}
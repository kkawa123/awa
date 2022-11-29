//
// Created by 86183 on 2022/9/28.
//
#include <stdio.h>

int main()
{
    int arr[] = {0};
    int i = 0;
    int ch;
    while ((ch = getchar()) != '\n')//别用 getchar 了 fuck

    {
        arr[i] = ch;
        i++;
    }
//    int arr0[] = {0};
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    int k = 0;
//    int n = 0;
//    for(n = 0; n <= sz - 1; n++)
//    {
//        for(k = 0; k <= 9; k++)
//        {
//            if(k == arr[n])
//            {
//                arr0[k]++;
//            }
//
//        }
//    }
    int j = 0;
    for (j = 0; j <= i; j++)
    {
        printf("%d\n", arr[j]);
    }


    return 0;
}
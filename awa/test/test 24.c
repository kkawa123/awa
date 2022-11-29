//
// Created by 86183 on 2022/9/28.
//
#include <stdio.h>

void my_array_copy(char *str, const char *arr, int size)
{
    int n = 0;
    for (n = 0; n <= size * 2 - 2; n++)
    {
        str[n] = arr[n];
    }
    str[n] = '\0';
}


int main()
{
    int n = 0;
    while(1)
    {
        scanf("%d", &n);
        if (0 == n)
            goto out;
        char arr0[] = "##############################################################";
        char arr1[] = "000000000000000000000000000000000000000000000000000000000000000";
        char arr2[] = "                                                                ";
        char arr3[] = "00000000000000000000000000000000000000000000000000000000000000000";
        my_array_copy(arr1, arr0, n);
        my_array_copy(arr3, arr2, n);
        int sz = n * 2;
        int left = 0;
        int right = sz - 2;

        while(left <= right)
        {
            printf("%s\n", arr1);
            arr1[left] = arr3[left];
            arr1[right] = arr3[right];
            left += 1;
            right -= 1;
        }
    }



    out:
    return 0;
}
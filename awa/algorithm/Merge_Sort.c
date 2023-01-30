//
// Created by 86183 on 2022/11/27.
//

/* 归并排序 */

#include<stdio.h>
#include<stdlib.h>

void Merge(int arr[], int tmp[], int start,int mid, int end)//合并小组并排序
{
    int i = start;//i标识//左小组的第一个元素位置
    int j = mid + 1;//j标识//右小组的第一个元素位置
    int k = start;//tmp当前小组存放的起始位置
    while (i < mid + 1 && j < end + 1)//左小组越界或右小组越界才能退出
    {
        if (arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
        }
    }

    while (j < end + 1)//如果右边小组没有越界
    {
        tmp[k++] = arr[j++];
    }

    while (i < mid + 1)//如果左边小组没有越界
    {
        tmp[k++] = arr[i++];
    }//哦哦就是补齐了，把数组放到新的那个临时数组中去了

    for (i = start; i <= end; i++)
    {
        arr[i] = tmp[i];
    }//至此，原来的数组已经排序完毕
}

void MergeS(int arr[], int tmp[], int start, int end)//划分小组，现在没有end.
{
    if (start < end)
    {
        int mid = (start+end)/2;
        MergeS(arr, tmp, start, mid);
        MergeS(arr, tmp, mid + 1, end);//自我递归调用
        Merge(arr, tmp, start, mid, end);//现在就全部排号
    }
}//就是递归调用呗

void MergeSort(int arr[], int len)
{
    int* tmp = (int*)malloc(sizeof(int) * len);//开了一个排序后结果保存的临时数组
    MergeS(arr, tmp, 0, len - 1);//嵌套调用
    free(tmp);
}

int main()
{
    int arr[] = { 12, 3, 21, 32, 1, 34, 12, 35, 34 };//举例子
    int len = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    return 0;
}

/* 就是先再定义一个一样长度的数组（malloc 出来），然后再把几个数拆成单个的数，比如有 8 个数，就先拆 1 ~ 4，再拆 1 ~ 2，最后 mid 变成 1，拆成 1 + 2
 * 1 和 2 两个元素开始排序，此时 1 2 有序，再拆 3 ~ 4，mid 变成 3，拆成 3 + 4，3 4 有序，排序 1 2 3 4，再拆 5 ~ 8 ... 依次类推 */

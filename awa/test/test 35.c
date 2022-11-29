//
// Created by 86183 on 2022/11/10.
//
#include <stdio.h>
#include <string.h>

int CompareMax(const char* old, const char* new)
{
    int i = 0;
    int sum = 0;
    if (new[i] < old[i])
    {
        return 1;
    }
    else if (new[i] > old[i])
    {
        return 0;
    }
    else
    {
        sum += CompareMax(++ old, ++ new);
        return sum;
    }
}

int CompareMin(const char* old, const char* new)
{
    int i = 0;
    int sum = 0;
    if (new[i] < old[i])
    {
        return 0;
    }
    else if (new[i] > old[i])
    {
        return 1;
    }
    else
    {
        sum += CompareMin(++ old, ++ new);
        return sum;
    }
}

void InitMax(char* str)
{
    int i;
    for (i = 0; i < 50; i ++)
    {
        str[i] = 127;
    }
}

void InitMin(char* str)
{
    int i;
    for (i = 0; i < 50; i ++)
    {
        str[i] = 0;
    }
}

int main()
{
    char word[50];
    char tmp1[50], tmp2[50];
    InitMax(tmp1);
    InitMin(tmp2);
    while (1)
    {
        printf("Enter word:");
        scanf("%s", word);
        int length = strlen(word);
        if (CompareMax(tmp1, word))
        {
            strcpy(tmp1, word);
        }
        if (CompareMin(tmp2, word))
        {
            strcpy(tmp2, word);
        }
        if (length == 4)
            break;
    }

    printf("Smallest word:%s\n", tmp1);
    printf("Largest word:%s\n", tmp2);

    return 0;
}
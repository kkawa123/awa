//
// Created by 86183 on 2023/1/1.
//

/* 洛谷 P1750 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *top;
    int *base;
    int *pop_elem;
    int stack_size;
}Stack;

void push_stack(Stack *s, int x)
{
    if (s -> top - s -> base > s -> stack_size)
    {
        return;
    }
    else
    {
        (s -> top)++;
        *(s -> top) = x;
    }
}

void pop_stack(Stack *s)
{
    if (s -> top == s -> base)
    {
        return;
    }
    else
    {
        s -> pop_elem = s -> top;
        (s -> top)--;
    }
}

int main()
{
    int count;
    int stack_size;
    scanf("%d%d", &count, &stack_size);

    Stack* s = (Stack *) malloc(sizeof(Stack));
    int *pTmp = (int *) malloc(sizeof(int[stack_size]));
    s -> base = pTmp - 1;
    s -> stack_size = stack_size;
    s -> top = s -> base;

    int *arr = (int *) malloc(sizeof(int) * count);
    int *tmpArr1 = arr;
    int *tmpArr2 = arr;
    for (int i = 0; i < count; i++)
    {
        scanf("%d", tmpArr1++);
    }

    for (int i = 0; i < count; i++)
    {
        if (i == 0)
        {
            push_stack(s, *(tmpArr2++));
        }
        else
        {
            while (*(s -> top) < *(tmpArr2) && s -> top - s -> base > 0) //两个条件，读取数大于栈顶数并且栈中有元素
            {
                int *tmpRet = NULL;
                int flag = 1;//第一次进 ret
                int n;//定位
                for (int j = 0; j < stack_size - (s -> top - s -> base) && j < count - i; j++) //向后读取到剩余容量
                {
                    if (*(tmpArr2 + j) < *(s -> top)) //如果能读取到比栈顶元素更小的数，那么先存起来，进行压栈操作，同时弹出最小数
                    {
                        if (tmpRet == NULL)
                        {
                            tmpRet = (int *) malloc(sizeof(int));
                        }
                        if (flag)
                        {
                            *tmpRet = *(tmpArr2 + j);
                            n = j;
                            flag = 0;
                        }
                        else
                        {
                            if (*(tmpArr2 + j) < *tmpRet)
                            {
                                *tmpRet = *(tmpArr2 + j);
                                n = j;
                            }
                        }
                    }
                }

                if (tmpRet != NULL) //存在小于栈顶元素的数
                {
                    for (int m = 0; m < n; m++)
                    {
                        push_stack(s, *(tmpArr2++));
                        i++;
                    }
                    printf("%d ", *(tmpArr2++));
                    goto next;
                }

                pop_stack(s);
                printf("%d ", *(s -> pop_elem));
            }
            if (s -> top - s -> base >= stack_size)
            {
                pop_stack(s);
                printf("%d ", *(s -> pop_elem));
                printf("%d ", *(tmpArr2++));
            }
            else
            {
                push_stack(s, *(tmpArr2++));
            }
        }
        next:
        ;
    }

    while (s -> top - s -> base > 0)
    {
        pop_stack(s);
        printf("%d ", *(s -> pop_elem));
    }

    return 0;
}
//
// Created by 86183 on 2023/1/6.
//

/* 洛谷 P2024 */

#include <stdio.h>

int find(int animal[], int i)
{
    int tmp = i;
    while (1)
    {
        if (animal[i] == i)
        {
            animal[tmp] = i;
            return i;
        }
        else
        {
            i = find(animal, animal[i]);
        }
    }
}

void unite(int animal[], int x, int y)
{
    x = find(animal, x);
    y = find(animal, y);

    if (x == y)
    {
        return;
    }
    animal[x] = y;
}

/* 关于为什么要设置三倍并查集：
 * 不知道你的动物到底属于哪组，所以要开三组，同时维护三组并查集
 * 但是确定假话的时候只需要根据其中一个链的情况就可以判断了，那为什么还要开三组？
 * 因为要确定动物之间的关系，处于不同分区的动物具有不同的关系
 * 思路不是要把同一组的动物放到一个集合里(其实是不用确定是哪种动物)，就可以判断出各种动物的关系怎么样
 * 上面的错误思路类似于开三个数组，把每一类的动物放到每一组里，再进行比较
 * 种类并查集确定的不是种类，而是关系 */

int main()
{
    int amount, count;
    scanf("%d %d", &amount, &count);
    int animal[3 * amount];

    for (int i = 0; i < 3 * amount; i++)
    {
        animal[i] = i;
    }

    int false = 0;
    for (int i = 0; i < count; i++)
    {
        int z, x, y;
        scanf("%d %d %d", &z, &x, &y);
        //特判
        if (x > amount || y > amount)
        {
            false++;
            continue;
        }

        if (z == 1)
        {
            if (find(animal, x - 1) == find(animal, y - 1 + amount) || find(animal, x - 1 + amount) == find(animal, y - 1))
            /* 是否同类：
             * 判定 x 吃 y -> x 与猎物集中的 y 查找，如果一致说明 x y 在一条食物链里
             * 不能简单判断 find(x), find(y) 差一个 amount，因为可能 y 的上级在第二区而 x 在第一区(不符合实际)
             * 判定 y 吃 x -> 同理 */
            {
                false++;
            }
            else
            {
                unite(animal, x - 1, y - 1);
                unite(animal, x - 1 + amount, y - 1 + amount);
                unite(animal, x - 1 + amount * 2, y - 1 + amount * 2);
            }
        }
        else if (z == 2)
        {
            int retX = find(animal, x - 1);
            int retY = find(animal, y - 1);
            if (retX == retY || find(animal, y - 1) == find(animal, x - 1 + amount))
            /* 注意：并查集是单项的，如果要查 y 吃 x，那么需要查询 y 的原集和 x 的猎物集 */
            {
                false++;
            }
            else
            {
                unite(animal, x - 1, y - 1 + amount);
                unite(animal, x - 1 + amount, y - 1 + 2 * amount);
                unite(animal, x - 1 + amount * 2, y - 1);
            }
        }

    }

    printf("%d", false);
    return 0;
}
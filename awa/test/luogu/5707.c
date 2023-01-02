//
// Created by 86183 on 2023/1/1.
//

/* 洛谷 P5707 */

#include <stdio.h>

int main()
{
    int s, v;
    scanf("%d%d", &s, &v);
    double tmpTime = s * 1.0 / v;
    int time;
    if ((int) tmpTime != tmpTime)
    {
        time = (int) tmpTime + 1;
    }
    else
    {
        time = (int) tmpTime;
    }

    time += 10;
    int hours = time / 60;
    time -= hours * 60;

    if (hours < 8)
    {
        printf("%02d:%02d", 8 - hours - 1, 60 - time);
    }
    else
    {
        printf("%02d:%02d", 31 - hours, 60 - time);
    }

    return 0;
}
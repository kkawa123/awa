//
// Created by 86183 on 2023/1/1.
//

/* 洛谷 P1421 */

#include <stdio.h>

int main()
{
    int yuan, jiao;
    scanf("%d%d", &yuan, &jiao);
    jiao = yuan * 10 + jiao;
    printf("%d", jiao / 19);

    return 0;
}
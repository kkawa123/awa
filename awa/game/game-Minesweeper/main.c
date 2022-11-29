//
// Created by 86183 on 2022/10/10.
//
#include "game-Minesweeper.h"

void menu()
{
    printf("**************************\n");
    printf("******    1.play    ******\n");
    printf("******    0.exit    ******\n");
    printf("**************************\n");
}

void game()
{
    printf("扫雷\n");
    //雷的信息存储
    // 1.布置好的雷的信息
    char mine[ROWS][COLS] = { 0 };
    // 2.排查出的雷的信息
    char show[ROWS][COLS] = { 0 };

    //初始化
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');

    //打印棋盘
    DisplayBoard(show, ROW, COL);

    //布置雷
    SetMine(mine, ROW, COL);

    //扫雷
    FindMine(mine, show, ROW, COL);


}

void test()
{
    int input = 0;
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误，请重新选择！\n");
                break;
        }
    }
    while (input);
}

int main()
{
    srand((unsigned int)time(NULL));
    test();
    return 0;
}

//补充 - 1.自动扩图
//      2.标记雷
//      3.查看还有几颗雷
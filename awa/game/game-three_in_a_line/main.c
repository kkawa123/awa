//
// Created by 86183 on 2022/10/8.
//
#include "game-three_in_a_line.h"

void menu()
{
    printf("******************************\n");
    printf("*****  1.play   0.exit  ******\n");
    printf("******************************\n");
}

void game()
{
    char ret = 0;
    //数组 - 存放玩家和电脑走出的棋盘信息
    char board[ROW][COL] = {0};//如果数值为 0，与空格看起来一样，因为ASCII码值 0 对应的是空
    //运用常量 - 增加可读性
    //棋盘初始化
    InitBoard(board, ROW, COL);
    //打印棋盘
    DisplayBoard(board, ROW, COL);
    //下棋
    while (1)
    {
        //玩家下棋
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        //判断玩家是否赢
        ret = IsWin(board, ROW, COL);
        if (ret != 'c')
        {
            break;
        }
        //电脑下棋
        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        //判断电脑是否赢
        ret = IsWin(board, ROW, COL);
        if (ret != 'c')
        {
            break;
        }
    }
    if (ret == 'X')
    {
        printf("恭喜你，你赢了\n");
    }
    else if (ret == 'O')
    {
        printf("很遗憾，你输了\n");
    }
    else
    {
        printf("平局，旗鼓相当的对手\n");
    }
}

void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));//时间戳 - 随机数生成器
    do
    {
        menu();
        printf("请选择(1/0):>");
        scanf("%d", &input);
        switch (input)
        {
            case 1:
                printf("三子棋\n");
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误，请重新选择!\n");
                break;
        }
    }
    while (input);
}


int main()
{
    test();

    return 0;
}
//
// Created by 86183 on 2022/10/8.
//
#include "game-three in a line.h"

//棋盘初始化
void InitBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)//行循环
    {
        printf("%d ", 3 - i);
       //以一个小格为单位，设置行/列循环
       int j = 0;
       for (j = 0; j < col; j++)//列循环 - 1.打印一行的数据
       {
           printf(" %c ", board[i][j]);
           if (j < col - 1)
               printf("|");
       }
       printf("\n");
       if (i < row - 1)
       {
           for (j = 0; j < col; j++)//列循环 - 2.打印分割符
           {
               if (j == 0)
               {
                   printf("  ---");
               }
               else if (j >= 1 && j < col)
               {
                   printf("---");
               }
               if (j < col - 1)
                   printf("|");
           }
           printf("\n");
       }
       if (2 == i)
       {
           printf("  ");
           for (j = 0; j < col; j++)
           {
               printf(" %d ", j + 1);
               printf(" ");
           }
           printf("\n");
       }
    }
}
//     |   |
//  ---|---|---
//     |   |
//  ---|---|---
//     |   |

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    while (1)
    {
        printf("玩家走:>\n");
        printf("请输入要下的坐标(中间用空格隔开):>");
        scanf("%d %d", &y, &x);
        //判断 x, y 坐标的合法性
        if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
        {
            if (board[3 - x][y - 1] == ' ')
            {
                board[3 - x][y - 1] = 'X';
                break;
            }
            else
            {
                printf("该坐标被占用，请重新输入\n");
            }
        }
        else
        {
            printf("坐标非法，请重新输入！\n");
        }
    }
}

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("电脑走:>\n");
    while (1)
    {
        x = rand() % row;
        y = rand() % col;
        if (board[x][y] == ' ')
        {
            board[x][y] = 'O';
            break;
        }
    }
}

//判断平局，1 表示满了，0 表示棋盘没满
int IsFull(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;//没满
            }
        }
    }
    return 1;//满了
}

//判断输赢
char IsWin(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++) //横三行
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) && (board[i][0] != ' '))
        {
            return board[i][0];
        }
    }
    for (i = 0; i < col; i++) //竖三列
    {
        if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]) && board[0][i] != ' ')
        {
            return board[0][i];
        }
    }
    //两个对角线
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) && (board[0][0] != ' '))
    {
        return board[0][0];
    }
    if ((board[0][2] == board[1][1] && board[1][1] == board [2][0]) && (board[1][1] != ' '))
    {
        return board[1][1];
    }
    //判断是否平局
    if (1 == IsFull(board, row, col))
    {
        return 't';
    }
    return 'c';
}
//告诉我们游戏的四种状态
// 1.玩家赢 - 'X'
// 2.电脑赢 - 'O'
// 3.平局 - 't'
// 4.继续 - 'c'






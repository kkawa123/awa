//
// Created by 86183 on 2022/10/10.
//
#include "game-Minesweeper.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 1;
    int j = 1;
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
        {
            if (1 == i)
            {
                printf(" ");
                printf(" %d", j);
            }
        }
        printf("\n");
        for (j = 1; j <= col; j++)
        {
            if (1 == j)
            {
                printf("%d", i);//打印行号
            }
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while (count)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        if (board[x][y] != '1')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

// '3' - ASCII码值 - 51
// '0' - ASCII码值 - 48
// '3' - '0' = 3
//同理 '1' - '0' = 1  '0' - '0' = 0
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    int a = 0;
    int b = 0;
    int mine_count = 0;
    for (a = x - 1; a <= x + 1; a++)
    {
        for (b = y - 1; b <= y + 1; b++)
        {
            if (a == x && b == y)
            {
                continue;
            }
            else
            {
                int tmp = mine[a][b] - '0';
                mine_count += tmp;
            }
        }
    }
    return mine_count;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int win = 0;
    while (win < row * col - EASY_COUNT)
    {
        int x = 0;
        int y = 0;
        printf("请输入排查雷的坐标(中间用空格隔开):>");
        scanf("%d %d", &x, &y);
        if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
        {
            //坐标合法
            if (mine[x][y] == '1') //踩雷
            {
                printf("很遗憾，你被炸死了\n");
                DisplayBoard(mine, row, col);
                break;
            }
            else //不是雷
            {
                //计算 x, y 坐标周围有几个雷
                int count = get_mine_count(mine, x, y);
                show[x][y] = count + '0';
                DisplayBoard(show, row, col);
                win++;
            }
        }
        else
        {
            printf("坐标非法，请重新输入！\n");
        }
    }
    if (win == row * col - EASY_COUNT)
    {
        printf("恭喜你，排雷成功\n");
    }
}
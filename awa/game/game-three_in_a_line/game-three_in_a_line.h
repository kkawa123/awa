//
// Created by 86183 on 2022/10/8.
//

#ifndef AWA_GAME_THREE_IN_A_LINE_H
#define AWA_GAME_THREE_IN_A_LINE_H

#define ROW 3 //行
#define COL 3 //列

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//函数声明
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);








#endif //AWA_GAME_THREE_IN_A_LINE_H

#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __MINE_H__
#define __MINE_H__

enum op
{
	EXIT,
	PLAY
};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COLS 11
#define ROWS 11
#define COUNT 30

void display(char show[ROWS][COLS]);
void inti_game(char mine[ROWS][COLS], char show[ROWS][COLS]);
void set_mine(char mine[ROWS][COLS]);//设置雷区
//void get_num(int x, int y);    //随机产生雷的位置
void sweep(char mine[ROWS][COLS], char show[ROWS][COLS]);  //开始扫雷
int get__mine(char mine[ROWS][COLS], int x, int y);   //附近雷的个数

#endif

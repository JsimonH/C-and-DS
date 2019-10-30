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
void set_mine(char mine[ROWS][COLS]);//��������
//void get_num(int x, int y);    //��������׵�λ��
void sweep(char mine[ROWS][COLS], char show[ROWS][COLS]);  //��ʼɨ��
int get__mine(char mine[ROWS][COLS], int x, int y);   //�����׵ĸ���

#endif

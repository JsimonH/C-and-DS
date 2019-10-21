#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("****************************\n");
	printf("******    1. play     ******\n");
	printf("******    0. exit     ******\n");
	printf("****************************\n");
}

void game()
{
	int choice = 0;
	int row = ROW, col = COL;
	char board[ROW][COL] = { 0 };
	char ret = 0;
	srand((unsigned int)time(NULL));
	InitBoard(board, row, col);
	DisplayBoard(board, row, col);
	do
	{
		printf("请输入1玩家先手，或2电脑先手进行选择：");
		scanf("%d", &choice);
		if (choice == 1 || choice == 2)
			break;
		else
			printf("输入错误，请重新选择。\n");
	} while (1);
	while (choice == 1)
	{
		PlayerMove(board, row, col);
		DisplayBoard(board, row, col);
		ret = IsWin(board, row, col);
		if (ret != 'C')
			break;
		ComputerMove(board, row, col);
		DisplayBoard(board, row, col);
		ret = IsWin(board, row, col);
		if (ret != 'C')
			break;
	}
	while (choice == 2)
	{
		ComputerMove(board, row, col);
		DisplayBoard(board, row, col);
		ret = IsWin(board, row, col);
		if (ret != 'C')
			break;
		PlayerMove(board, row, col);
		DisplayBoard(board, row, col);
		ret = IsWin(board, row, col);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("恭喜玩家胜利！\n");
	else if (ret == '#')
		printf("电脑胜利！\n");
	else
		printf("平局！\n");
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请输入数字选择->");
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
			printf("输入有误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}

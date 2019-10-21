#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
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

void InitBoard(char board[ROW][COL], int row, int col)
{
	memset(board, ' ', col*row);  //将棋盘初始化为‘ ’空格符号，效率更高
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	//控制行数
	for(i=0; i<row; i++)
	{
		int j = 0;
		//打印一行数据
		for(j=0; j<col; j++)
		{
			printf(" %c ", board[i][j]);	
			if(j<col-1)
				printf("|");
		}
		printf("\n");
		//打印分割行
		if(i<row-1)
		{
			for(j=0; j<col; j++)
			{
				printf("---");
				if(j<col-1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("玩家下棋：\n");
	while (1)
	{
		printf("请输入下棋的位置：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("坐标已被占用，请重新输入。\n");
		}
		else
			printf("坐标非法，请重新输入。\n");
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	char win = 0;
	printf("电脑下棋：\n");
	while (1)
	{
		//如果可以则先占据中心点
		if (board[1][1] == ' ')
		{
			board[1][1] = '#';
			break;
		}
		//遍历检测空位，判断下#是否能赢，能赢则下
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = '#';
					win = IsWin(board, row, col);
					if (win != '#')
						board[i][j] = ' ';
					else
						goto end;
				}
			}
		}
		//遍历检测空位，判断下*玩家是否能赢，能则堵住该位置
		if (win != '#')
		{
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
				{
					if (board[i][j] == ' ')
					{
						board[i][j] = '*';
						win = IsWin(board, row, col);
						if (win != '*')
							board[i][j] = ' ';
						else
						{
							board[i][j] = '#';
							goto end;
						}
					}
				}
			}
		}
		//若以上均不达到，则优先下在角位置（第一次对手占据中心则下在一个角）
		if (board[0][0] == ' ')
		{
			board[0][0] = '#';
			break;
		}
		else if (board[0][3] == ' ')
		{
			board[0][3] = '#';
			break;
		}
		else if (board[3][0] == ' ')
		{
			board[3][0] = '#';
			break;
		}
		else if (board[3][3] == ' ')
		{
			board[3][3] = '#';
			break;
		}
		//以上除外则随机寻找位置
		while (1)
		{
			i = rand() % row;
			j = rand() % col;
			if (board[i][j] == ' ')
			{
				board[i][j] = '#';
				goto end;
			}
		}
	}
end:
	;
}

static int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	int flag = 0;
	//一行相等
	for (i = 0; i < row; i++)
	{
		flag = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == '*')
				;
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
			return '*';
	}
	for (i = 0; i < row; i++)
	{
		flag = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == '#')
				;
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
			return '#';
	}
	//一列相等
	for (i = 0; i < row; i++)
	{
		flag = 0;
		for (j = 0; j < col; j++)
		{
			if (board[j][i] == '*')
				;
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
			return '*';
	}
	for (i = 0; i < row; i++)
	{
		flag = 0;
		for (j = 0; j < col; j++)
		{
			if (board[j][i] == '#')
				;
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
			return '#';
	}
	//主对角线相等
	flag = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][i] == '*')
			;
		else
		{
			flag = 1;
			break;
		}

	}
	if (flag != 1)
		return '*';
	flag = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][i] == '#')
			;
		else
		{
			flag = 1;
			break;
		}

	}
	if (flag != 1)
		return '#';
	//副对角线相等
	flag = 0;
	for (i = 0, j = col - 1; i < row, j >= 0; i++, j--)
	{
		if (board[i][j] == '*')
			;
		else
		{
			flag = 1;
			break;
		}

	}
	if (flag != 1)
		return '*';

	flag = 0;
	for (i = 0, j = col - 1; i < row, j >= 0; i++, j--)
	{
		if (board[i][j] == '#')
			;
		else
		{
			flag = 1;
			break;
		}

	}
	if (flag != 1)
		return '#';
	//均不相等
	if (flag)
	{
		if (IsFull(board, row, col))
			return 'Q';
		else
			return 'C';
	}
	//解决不是所有控件路径都返回值的警告
	else
	{
		return 'C';
	}
}

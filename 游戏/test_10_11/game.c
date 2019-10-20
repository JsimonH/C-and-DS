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
		printf("������1������֣���2�������ֽ���ѡ��");
		scanf("%d", &choice);
		if (choice == 1 || choice == 2)
			break;
		else
			printf("�������������ѡ��\n");
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
		printf("��ϲ���ʤ����\n");
	else if (ret == '#')
		printf("����ʤ����\n");
	else
		printf("ƽ�֣�\n");
}

void InitBoard(char board[ROW][COL], int row, int col)
{
	memset(board, ' ', col*row);  //�����̳�ʼ��Ϊ�� ���ո���ţ�Ч�ʸ���
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf(" %c |", board[i][j]);
			else
				printf(" %c \n", board[i][j]);
		}
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf("---|", board[i][j]);
			else
				printf("---\n", board[i][j]);
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("������壺\n");
	while (1)
	{
		printf("�����������λ�ã�");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�����ѱ�ռ�ã����������롣\n");
		}
		else
			printf("����Ƿ������������롣\n");
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	char win = 0;
	printf("�������壺\n");
	while (1)
	{
		//�����������ռ�����ĵ�
		if (board[1][1] == ' ')
		{
			board[1][1] = '#';
			break;
		}
		//��������λ���ж���#�Ƿ���Ӯ����Ӯ����
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
		//��������λ���ж���*����Ƿ���Ӯ�������ס��λ��
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
		//�����Ͼ����ﵽ�����������ڽ�λ�ã���һ�ζ���ռ������������һ���ǣ�
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
		//���ϳ��������Ѱ��λ��
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
	//һ�����
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
	//һ�����
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
	//���Խ������
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
	//���Խ������
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
	//�������
	if (flag)
	{
		if (IsFull(board, row, col))
			return 'Q';
		else
			return 'C';
	}
	//����������пؼ�·��������ֵ�ľ���
	else
	{
		return 'C';
	}
}

#include "sweep.h"

void inti_game(char mine[ROWS][COLS], char show[ROWS][COLS])
{
	memset(mine, '0', ROWS*COLS*sizeof(char));
	memset(show, '*', ROWS*COLS*sizeof(char));
	set_mine(mine);
}

int get_mine_num(int x, int y)
{
	return rand() % (y - x + 1) + x;
}

void set_mine(char mine[ROWS][COLS])
{
	int count = COUNT;
	int x = 0;
	int y = 0;
	srand((unsigned)time(NULL));
	while (count)
	{
		x = get_mine_num(1, 9);
		y = get_mine_num(1, 9);
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

void display(char show[ROWS][COLS])  //��ӡ������
{
	int i = 0;
	int j = 0;
	printf(" ");
	for (i = 1; i < COLS - 1; i++)
	{
		printf(" %d ", i);
	}
	printf("\n");
	for (i = 1; i < ROWS - 1; i++)
	{
		printf("%d", i);
		for (j = 1; j < COLS - 1; j++)
		{
			printf(" %c ", show[i][j]);
		}
		printf("\n");
	}
}

void sweep(char mine[ROWS][COLS], char show[ROWS][COLS])
{
	int count = 0;
	int x = 0;
	int y = 0;
	while (count != ((ROWS - 2)*(COLS - 2) - COUNT))
	{
		printf("���������꣺\n");
		scanf("%d%d", &x, &y);
		if (mine[x][y] == '1')
		{
			printf("�����ˣ�\n");
			return;
		}
		else
		{
			int ret = get__mine(mine, x, y);
			show[x][y] = ret + '0';
			display(show);
			count++;
		}
	}
	printf("��ϲ��Ӯ�ˣ�\n");
	display(mine);
}
int get__mine(char mine[ROWS][COLS], int x, int y)   //�����׵ĸ���
{
	int count = 0;
	if (mine[x + 1][y + 1] == '1')count++;
	if (mine[x + 1][y - 1] == '1')count++;
	if (mine[x + 1][y] == '1')count++;

	if (mine[x - 1][y + 1] == '1')count++;
	if (mine[x - 1][y - 1] == '1')count++;
	if (mine[x - 1][y] == '1')count++;

	if (mine[x][y + 1] == '1')count++;
	if (mine[x][y - 1] == '1')count++;

	return count;
}

#include "sweep.h"
void menu()
{
	printf("**********************\n");
	printf("****** 1.play  ******\n");
	printf("****** 0.exit  ******\n");
	printf("**********************\n");
}

void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	inti_game(mine, show);
	display(show);
	//display(mine);
	sweep(mine, show);
}

void test()
{
	int input;
	do
	{
		menu();
		printf("������ѡ��->:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ .\n");
			break;
		default:
			printf("������������ȷѡ�\n");
			break;
		}

	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}

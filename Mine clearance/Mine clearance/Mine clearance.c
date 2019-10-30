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
		printf("请输入选择->:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏 .\n");
			break;
		default:
			printf("请重新输入正确选项：\n");
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

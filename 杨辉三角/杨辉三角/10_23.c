#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a[10][10] = {0};
	int i=0;
	int j=0;
	for (i = 0; i<10; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (i == j || j == 0)
			{
				a[i][j] = 1;  //每行的的首末位置的数均为1
			}
			else
			{
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];  //每个数等于上一行的对应位置的前两个数的和
			}
			printf("%7d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

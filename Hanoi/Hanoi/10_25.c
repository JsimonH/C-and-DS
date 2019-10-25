#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void Hanoi(int n, char A, char B, char C)
{
	if (1 == n)
	{
		printf("%c---->%c\n", A, C);//如果是1，直接从A-->C
	}
	else
	{
		Hanoi(n - 1, A, C, B);//现将n - 1 个从A--->B,借助C完成
		printf("%c--->%c\n", A, C);//再将A最后的一个盘子从A到C
		Hanoi(n - 1, B, A, C);//再将B中的n - 1个盘子借助C完成从 B-->A
	}
}
int main()
{
	int n = 0;
	char A = 'a';
	char B = 'b';
	char C = 'c';
	printf("盘子的个数:>");
	scanf("%d", &n);
	Hanoi(n, A, B, C);
	return 0;
}
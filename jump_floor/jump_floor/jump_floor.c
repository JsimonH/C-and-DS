#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int jump_floor1(int n)//递归
{
	if (n <3)
	{
		return n;
	}
	else
	{
		return jump_floor1(n - 2) + jump_floor1(n - 1);
	}
}

int jump_floor2(int n)//非递归
{
	int a = 2;
	int b = 3;
	int c = 0;
	if (n == 1 || n == 2||n==3)
	{
		return n;
	}
	while (n>3)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	printf("请输入跳的台阶数：");
	scanf("%d", &n);
	int ret1 = jump_floor1(n);
	int ret2 = jump_floor2(n);
	printf("%d\n", ret1);
	printf("%d\n", ret2);
	return 0;
}

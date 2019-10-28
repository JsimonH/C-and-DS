#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int jump_floor1(int n)//µÝ¹é
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

int jump_floor2(int n)//·ÇµÝ¹é
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n--)
	{
		a = b;
		b = c;
		c = a + b;
	}
	return a;
}

int main()
{
	int n = 0;
	printf("ÇëÊäÈëÌøµÄÌ¨½×Êý£º");
	scanf("%d", &n);
	int ret1 = jump_floor1(n);
	int ret2 = jump_floor2(n);
	printf("%d\n", ret1);
	printf("%d\n", ret2);
	return 0;
}

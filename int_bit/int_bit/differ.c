#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int differ_bits(int m, int n)
{
	int count = 0;
	int ret = m^n;
	while (ret)
	{
		ret = ret&(ret - 1);
		count++;
	}
	return count;
}

int main()
{
	int m, n;
	printf("请输入两位整数：\n");
	scanf("%d%d", &m, &n);
	printf("%d\n", differ_bits(m, n));
	return 0;
}
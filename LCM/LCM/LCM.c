#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a, b;
	int i;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		if (a > b)		//比较a,b大小；将大的放在b中，小的放在a中
		{
			int temp;
			temp = a;
			a = b;
			b = temp;
		}
		for (i = 1; i <= a; i++)
		{
			if (i*b % a == 0)
			{
				printf("最小公倍数为:%d\n", i*b);
				break;
			}
		}
	}
	return 0;
}
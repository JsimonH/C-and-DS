#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a, b;
	int i;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		if (a > b)		//�Ƚ�a,b��С������ķ���b�У�С�ķ���a��
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
				printf("��С������Ϊ:%d\n", i*b);
				break;
			}
		}
	}
	return 0;
}
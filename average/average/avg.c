#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ�� 
//����һ
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf("%d%d", &num1, &num2);
//	int avg = num1 - (num1 - num2) / 2;
//	printf("%d\n", avg);
//	return 0;
//}

//������
int add(int x, int y)//������ʵ�ּӷ��ĺ���
{
	int tmp = 0;
	do
	{
		tmp = x^y;
		y = x&y;
		x = tmp;
		y <<= 1;//��λ
	} while (y != 0);
	return x;
}

int avg(int x, int y)//��������ƽ��ֵ�ĺ���
{
	return add(((x^y) >> 1), x&y);
}

int main()
{
	int a = 0;
	int b = 0;
	printf("Input two number:");
	scanf("%d%d", &a, &b);
	printf("%d\n", avg(a, b));
	return 0;
}
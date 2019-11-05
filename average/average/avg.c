#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//不使用（a+b）/2这种方式，求两个数的平均值。 
//方法一
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf("%d%d", &num1, &num2);
//	int avg = num1 - (num1 - num2) / 2;
//	printf("%d\n", avg);
//	return 0;
//}

//方法二
int add(int x, int y)//①用来实现加法的函数
{
	int tmp = 0;
	do
	{
		tmp = x^y;
		y = x&y;
		x = tmp;
		y <<= 1;//进位
	} while (y != 0);
	return x;
}

int avg(int x, int y)//②用来求平均值的函数
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
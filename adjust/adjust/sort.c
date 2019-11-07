#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
/*
输入一个整数数组，实现一个函数，
来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
所有偶数位于数组的后半部分。
*/
//冒泡法
//void Sort(int num[], int len) 
//{
//	for (int i = 0; i < len - 1; ++i) 
//	{
//		for (int j = 0; j < len - i - 1; ++j) 
//		{
//			if (num[j] % 2 == 0 && num[j + 1] % 2 != 0) 
//			{
//				int tmp = num[j];
//				num[j] = num[j + 1];
//				num[j + 1] = tmp;
//			}
//		}
//	}
//}

void Sort(int* num, int len) 
{
	for (int i = 0; i < len - 1; ++i) 
	{
		for (int j = 0; j < len - i - 1; ++j) 
		{
			if (*(num + j) % 2 == 0 && *(num + j + 1) % 2 != 0) 
			{
				int tmp = *(num + j);
				*(num + j) = *(num + j + 1);
				*(num + j + 1) = tmp;
			}
		}
	}
}

int main() 
{
	int num[] = { 6, 2, 9,3, 4, 7, 8, 12, 1 };
	int sz = sizeof(num) / sizeof(num[1]);
	Sort(num, sz);
	for (int i = 0; i < sz; i++) 
	{
		printf("%d ", num[i]);
	}
	printf("\n");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
/*
����һ���������飬ʵ��һ��������
�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
����ż��λ������ĺ�벿�֡�
*/
//ð�ݷ�
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

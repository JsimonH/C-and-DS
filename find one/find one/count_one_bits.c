#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int count_one_bits(unsigned int value)
{
	int count = 0;
	for (int i = 0; i < 32; i++){
		if ((value & (1 << i)) != 0){
			count++;
		}
	}
	return count;
}

int main()
{
	int num;
	printf("请输入一个整数：\n");
	scanf("%d", &num);
	printf("这个整数的二进制序列中有%d个1！\n", count_one_bits(num));
	return 0;
}

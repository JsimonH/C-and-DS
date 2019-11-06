#define _CRT_SECURE_NO_WARNINGS 1
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。 请找出这个数字。（使用位运算）

#include<stdio.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 3, 2, 1, 5 };
	int i = 0;
	int ret = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i<len; i++)//依次异或抵消掉成对出现的
	{
		ret ^= arr[i];
	}
	printf("出现一次的数为:>%d\n", ret);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ� ���ҳ�������֡���ʹ��λ���㣩

#include<stdio.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 3, 2, 1, 5 };
	int i = 0;
	int ret = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i<len; i++)//�������������ɶԳ��ֵ�
	{
		ret ^= arr[i];
	}
	printf("����һ�ε���Ϊ:>%d\n", ret);
	return 0;
}
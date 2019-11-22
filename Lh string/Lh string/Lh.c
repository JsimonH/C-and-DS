#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

void Left_Handed(char *str, int len, int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		int j = 0;
		char tmp = str[0];
		for (j = 0; j < len; j++)
		{
			str[j] = str[j + 1];
		}
		str[len - 1] = tmp;
	}
}

int main()
{
	char arr[] = "ABCD";
	int sz = strlen(arr);
	int num = 0;
	printf("请输入你要旋转几位\n");
	scanf("%d", &num);
	while (num<1 || num>sz - 1)//输入错误，重新输入
	{
		printf("输入错误，请重新输入！\n");
		scanf("%d", &num);
	}
	Left_Handed(arr, sz, num);
	printf("旋转后:%s\n", arr);
	return 0;
}

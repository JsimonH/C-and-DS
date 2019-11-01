#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char a[30];
	char *p;
	int i = 0, j = 0, m = 0, n = 0, k = 0;
	p = a;
	printf("请输入一段文字:\n");
	gets(a);
	while (*p != '\0') //当字符不为结束符时，执行操作
	{
		if (*p >= 'A'&&*p <= 'Z')
		{
			i++;
		}
		else if (*p >= 'a'&&*p <= 'z')
		{
			j++;
		}
		else if (*p >= '0'&&*p <= '9')
		{
			m++;
		}
		else if (*p == ' ')
		{
			n++;
		}
		else
		{
			k++;
		}
		p++;  //执行完一轮后，将指针的地址指向下一个字符，继续检查
	}
	printf("大写字母:%d\n小写字母:%d\n数字:%d\n空格:%d\n其他字符:%d\n", i, j, m, n, k);
	return 0;
}
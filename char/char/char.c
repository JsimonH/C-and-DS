#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char a[30];
	char *p;
	int i = 0, j = 0, m = 0, n = 0, k = 0;
	p = a;
	printf("������һ������:\n");
	gets(a);
	while (*p != '\0') //���ַ���Ϊ������ʱ��ִ�в���
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
		p++;  //ִ����һ�ֺ󣬽�ָ��ĵ�ַָ����һ���ַ����������
	}
	printf("��д��ĸ:%d\nСд��ĸ:%d\n����:%d\n�ո�:%d\n�����ַ�:%d\n", i, j, m, n, k);
	return 0;
}
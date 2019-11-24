#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void  reserve_size(char *pleft, char *pright)
{
	while (pleft<pright)
	{
		char tep = *pleft;
		*pleft = *pright;
		*pright = tep;
		++pleft;
		--pright;
	}
}
int  strlen(char*arr)
{
	int count = 0;
	while (*arr++)
	{
		count++;
	}
	return count;
}
void  reserve(char *arr)
{
	int len = strlen(arr);
	//�Ƚ��ַ�������
	reserve_size(arr, arr + len - 1);//����ת�� ���Ϊi ma a tneduts
	char *pstart = arr;//���嵥�ʿ�ͷ
	while (*arr)
	{
		pstart = arr;//��pstart���¶���
		char *pend = arr;//�տ�ʼ��ʱ��ͷ��ĩβ�غ�
		//�ҵ���ĩβ
		while (' ' != *pend && *pend != '\0')
		{
			++pend;//�ҵ��ʵ�ĩβ
		}
		reserve_size(pstart, pend - 1);//  ��ÿ�����ʽ���ת��  �ҵ��˵���ĩβ��֮�󵥴ʽ���ת�ã���Ϊend�����ڿո��λ�ã����Դ���pend-1
		arr = pend;//�ѿ�ʼ��λ�����ڷ���pend������Ӱ��pstart

		if (*arr == ' ')
		{
			++arr;//��Ϊarr���ڿո񴦣��ո񲻲��뽻������������������һ�£����Ǳ����ǿո������\0;�ͻ��޷�ֹͣ������Ҫ��if���жϣ�������ֱ�Ӽ�1
			continue;
		}
	}
}
int main()
{
	char arr[] = "student a am i";
	reserve(arr);
	printf("%s", arr);
	printf("\n");
}



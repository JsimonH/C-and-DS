#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void ReplaceSpace(char str[], int length)
{
	if (str == NULL || length <= 0)
	{
		return;
	}
	int LenSpace = 0;		//�ո񳤶�
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			++LenSpace;
		}
		i++;
	}
	//�滻����ַ����ĳ���
	int NewLength = length + LenSpace * 2;
	while (length >= 0 && length < NewLength)
	{
		if (str[length] == ' ')
		{
			str[NewLength--] = '0';
			str[NewLength--] = '2';
			str[NewLength--] = '%';
		}
		else
		{
			str[NewLength--] = str[length];
		}
		length--;
	}
}
int main()
{
	char str[32] = "We are happy.";
	int len = strlen(str);
	printf("�滻ǰ���ַ���Ϊ��");
	for (int i = 0; i < len; i++)
	{
		printf("%c", str[i]);
	}
	ReplaceSpace(str, len);
	int len1 = strlen(str);
	printf("\n�滻����ַ���Ϊ��");
	for (int i = 0; i < len1; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void Hanoi(int n, char A, char B, char C)
{
	if (1 == n)
	{
		printf("%c---->%c\n", A, C);//�����1��ֱ�Ӵ�A-->C
	}
	else
	{
		Hanoi(n - 1, A, C, B);//�ֽ�n - 1 ����A--->B,����C���
		printf("%c--->%c\n", A, C);//�ٽ�A����һ�����Ӵ�A��C
		Hanoi(n - 1, B, A, C);//�ٽ�B�е�n - 1�����ӽ���C��ɴ� B-->A
	}
}
int main()
{
	int n = 0;
	char A = 'a';
	char B = 'b';
	char C = 'c';
	printf("���ӵĸ���:>");
	scanf("%d", &n);
	Hanoi(n, A, B, C);
	return 0;
}
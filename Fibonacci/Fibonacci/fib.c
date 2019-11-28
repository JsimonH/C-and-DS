#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int a = 1;
	int b = 0;
	int c = 0;
	int N = 0;
	scanf("%d", &N);
	int L = 0;
	int R = 0;
	int min = 0;
	while (1)
	{
		c = a + b;
		a = b;
		b = c;     
		if (c < N)
		{
			L = N - c;
		}
		else
		{
			R = (a + b) - N;
			break;
		}
	}
	min = L < R? L : R;
	printf("%d\n", min);
	return 0;
}
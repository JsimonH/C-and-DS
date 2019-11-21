#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	unsigned int z = 0;
	for (i = 0; i<32; i++)
	{
		z += ((value >> i) & 1)*(unsigned int)pow(2, 31 - i);
	}
	return z;
}

int main()
{
	int n = 25;
	unsigned int z = 0;
	z = reverse_bit(n);
	printf("翻转之后结果:%u\n", z);
}
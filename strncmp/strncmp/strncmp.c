#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

int Strncmp(const char* str1, const char* str2, size_t n) 
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (n && *str1 == *str2) 
	{
		if (*str1 == '\0' || *str2 == '\0') 
		{
			break;
		}
		++str1;
		++str2;
		--n;
	}
	if (n == 0) 
	{
		return 0;
	}
	return *str1 - *str2;
}

int main() 
{
	char str1[] = "happy";
	char str2[] = "happiness";
	int ret = Strncmp(str1, str2, 5);
	printf("%d\n", ret);
	return 0;
}

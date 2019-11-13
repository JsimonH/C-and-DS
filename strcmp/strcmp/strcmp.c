#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

int Strcmp(const char* str1, const char* str2) 
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (*str1 == *str2) 
	{
		if (*str1 == '\0') 
		{
			return 0;
		}
		++str1;
		++str2;
	}
	return *str1 - *str2;
}

int main() 
{
	char str1[] = "welcome";
	char str2[] = "hello";
	int ret = Strcmp(str1, str2);
	if (ret == 0) 
	{
		printf("str1 = str2\n");
	}
	else if (ret > 0) 
	{
		printf("str1 > str2\n");
	}
	else  
		printf("str1 < str2\n");
	return 0;
}

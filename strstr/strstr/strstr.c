#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

char* Strstr(const char* str1, const char* str2) 
{
	int n = strlen(str2);
	for (; *str1 != 0; ++str1) 
	{
		if (strncmp(str1, str2, n) == 0) 
		{
			return (char*)str1;
		}
	}
	return NULL;
}

int main() 
{
	char str1[20] = "abcdef";
	char str2[7] = "abc";
	char str3[5] = "acdz";
	printf("%s\n", Strstr(str1, str2));
	printf("%s\n", Strstr(str1, str3));
	return 0;
}

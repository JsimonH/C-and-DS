#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

char* Strncat(char* dest, const char* src, size_t n) 
{
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest != '\0') 
	{
		++dest;
	}
	while (n) 
	{
		if (*src == '\0') 
		{
			break;
		}
		*dest++ = *src++;
		--n;
	}
	*dest = '\0';
	return dest;
}

int main() 
{
	char str1[30] = "How are you?";
	char str2[] = "Fine.Thanks!";
	Strncat(str1, str2, 5);
	printf("%s\n", str1);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

char* Strncpy(char* dest, const char* src, size_t n)
{
	assert(dest != NULL);
	assert(src != NULL);
	while (n) 
	{
		if (src == NULL) 
		{
			break;
		}
		*dest++ = *src++;
		--n;
	}
	return dest;
}

int main() 
{
	char str1[10] = { 0 };
	char str2[] = "I like U";
	Strncpy(str1, str2, 6);
	printf("%s\n", str1);
	return 0;
}


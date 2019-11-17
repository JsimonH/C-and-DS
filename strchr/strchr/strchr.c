#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
const char* Strchr(const char* str, int c) 
{
	assert(str != NULL);
    const char* match = str;
	while (*match != '\0')
	{
		if (*match == c) 
		{
			return match;
		}
		++match;
	}
	return NULL;
}

int main() 
{
	char str1[] = "I will win!";
    char* str = Strchr(str1, 'w');
	printf("%s\n", str);
	return 0;
}


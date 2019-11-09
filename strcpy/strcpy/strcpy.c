#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>    
#include <assert.h>
char* My_Strcpy(char* des, const char* src) 
{
	assert(des != NULL);
	assert(src != NULL);
	while (*src != '\0') 
	{
		*des++ = *src++;
	}
	*des = *src;
	return des;
}

int main() 
{
	char str1[20] = "lyy";
	char str2[] = "I love you!";
	My_Strcpy(str1, str2);
	printf("%s\n", str1);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h> 
#include <assert.h>
/*memmove函数的功能同memcpy基本一致，但是当src区域和dst内存区域重叠时,
memcpy可能会出现错误，而memmove能正确进行拷贝。*/
void * Memmove(void * dst, const void * src, size_t count)
{
	assert(dst != NULL);
	assert(src != NULL);
	void * ret = dst;
	if (dst <= src || (char *)dst >= ((char *)src + count))
	{
		while (count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst + 1;
			src = (char *)src + 1;
		}
	}
	else
	{
		dst = (char *)dst + count - 1;
		src = (char *)src + count - 1;
		while (count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst - 1;
			src = (char *)src - 1;
		}
	}
	return ret;
}

int main(){
	char arr1[10] = {0};
	char arr2[10] = "ABCDEF";
	Memmove(arr1, arr2, 3);
	printf("%s\n", arr1);
	return 0;
}

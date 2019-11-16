#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h> 
#include <assert.h>
/*memmove�����Ĺ���ͬmemcpy����һ�£����ǵ�src�����dst�ڴ������ص�ʱ,
memcpy���ܻ���ִ��󣬶�memmove����ȷ���п�����*/
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

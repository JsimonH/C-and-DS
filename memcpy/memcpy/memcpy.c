#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

void* my_memcpy(void* dest, const void* src, size_t n)    /*memcpy是内存拷贝函数，所以必须什么类型都能接收
													       所以此处用void*做参数类型和返回值类型*/
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	while (n--)
	{/*void类型不能进行解引用操作，所以要进行强制类型转化因为此处n指的是字节数
	 需要一个字节一个字节拷贝，所以强制类型转化为char* */
		*(char*)dest = *(const char*)src;
	//void*类型不能进行++操作，所以要进行强制类型转化		
		++(char*)dest;                   
		++(char*)src;
	}
	return ret;
}

int main()
{
	char* str1[10] = { 0 };
	char* str2 = "abcdefg";
	char* ret = NULL;
	ret = my_memcpy(str1, str2, 5);//n代表的是字节数
	printf("%s\n", ret);
	return 0;
}
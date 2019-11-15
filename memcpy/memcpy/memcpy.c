#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

void* my_memcpy(void* dest, const void* src, size_t n)    /*memcpy���ڴ濽�����������Ա���ʲô���Ͷ��ܽ���
													       ���Դ˴���void*���������ͺͷ���ֵ����*/
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	while (n--)
	{/*void���Ͳ��ܽ��н����ò���������Ҫ����ǿ������ת����Ϊ�˴�nָ�����ֽ���
	 ��Ҫһ���ֽ�һ���ֽڿ���������ǿ������ת��Ϊchar* */
		*(char*)dest = *(const char*)src;
	//void*���Ͳ��ܽ���++����������Ҫ����ǿ������ת��		
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
	ret = my_memcpy(str1, str2, 5);//n��������ֽ���
	printf("%s\n", ret);
	return 0;
}
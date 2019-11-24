#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void  reserve_size(char *pleft, char *pright)
{
	while (pleft<pright)
	{
		char tep = *pleft;
		*pleft = *pright;
		*pright = tep;
		++pleft;
		--pright;
	}
}
int  strlen(char*arr)
{
	int count = 0;
	while (*arr++)
	{
		count++;
	}
	return count;
}
void  reserve(char *arr)
{
	int len = strlen(arr);
	//先将字符串逆置
	reserve_size(arr, arr + len - 1);//整体转置 结果为i ma a tneduts
	char *pstart = arr;//定义单词开头
	while (*arr)
	{
		pstart = arr;//给pstart重新定义
		char *pend = arr;//刚开始的时候开头和末尾重合
		//找单词末尾
		while (' ' != *pend && *pend != '\0')
		{
			++pend;//找单词的末尾
		}
		reserve_size(pstart, pend - 1);//  将每个单词进行转置  找到了单词末尾，之后单词进行转置，因为end现在在空格的位置，所以传入pend-1
		arr = pend;//把开始的位置现在放在pend处，来影响pstart

		if (*arr == ' ')
		{
			++arr;//因为arr是在空格处，空格不参与交换，所以让他朝后走一下，但是必须是空格，如果是\0;就会无法停止，所以要用if来判断，而不是直接加1
			continue;
		}
	}
}
int main()
{
	char arr[] = "student a am i";
	reserve(arr);
	printf("%s", arr);
	printf("\n");
}



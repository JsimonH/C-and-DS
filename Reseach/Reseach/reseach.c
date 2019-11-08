#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

/*杨氏矩阵 
有一个二维数组. 
数组的每行从左到右是递增的，每列从上到下是递增的. 
在这样的数组中查找一个数字是否存在。 
时间复杂度小于O(N)*/

int Reseach(int arr[][3], int row, int col, int num)
{
	int i = 0;
	int j = col - 1;
	//从第一行,最后一列开始寻找
	while ((j >= 0) && (i <= 2))
	{
		if (arr[i][j] == num)
			return 1;
		else if (arr[i][j] <num)
			i++;
		else
			j--;
	}
	return 0;
}

int main()
{
	int arr[][3] = { 1, 2, 3, 2, 3, 4, 3, 4, 5 };
	int target = 0;
	int row = 3;
	int col = 3;
	printf("请输入想要查找的数字:>\n");
	scanf("%d", &target);
	int ret=Reseach(arr, row, col, target);
	if (ret==1)
		printf("找到了!\n");
	else
		printf("没找到!\n");
	return 0;
}

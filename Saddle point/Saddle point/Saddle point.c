#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a[4][5];
	int i, j, k, m = 0, n = 0, max = 0, min = 0, temp = 0;
	printf("输入数组的值：\n");
	for (i = 0; i<4; i++)//键盘输入二维数组的值 
	for (j = 0; j<5; j++)
		scanf("%d", &a[i][j]);
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<5; j++)//获得i行最大值 
		if (a[i][m]<a[i][j])
		{
			m = j;
			a[i][m] = a[i][j];
		}
		max = a[i][m];//存储该行最大值所在的列为m                                     
		min = a[0][m];//存储m列的最小值 
		for (k = 0; k<4; k++)
		if (a[k][m]<min)//获得该列最小值 
		{
			min = a[k][m];
			n = k;
		}
		if (max == min){//若相等则有鞍点，循环结束 
			temp = 1;
			printf("鞍点为：a[%d][%d]=%d\n", n, m, a[n][m]);
			break;
		}
	}
	if (temp == 0)
		printf("该二维数组不存在鞍点！");
}

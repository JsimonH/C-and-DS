#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a[4][5];
	int i, j, k, m = 0, n = 0, max = 0, min = 0, temp = 0;
	printf("���������ֵ��\n");
	for (i = 0; i<4; i++)//���������ά�����ֵ 
	for (j = 0; j<5; j++)
		scanf("%d", &a[i][j]);
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<5; j++)//���i�����ֵ 
		if (a[i][m]<a[i][j])
		{
			m = j;
			a[i][m] = a[i][j];
		}
		max = a[i][m];//�洢�������ֵ���ڵ���Ϊm                                     
		min = a[0][m];//�洢m�е���Сֵ 
		for (k = 0; k<4; k++)
		if (a[k][m]<min)//��ø�����Сֵ 
		{
			min = a[k][m];
			n = k;
		}
		if (max == min){//��������а��㣬ѭ������ 
			temp = 1;
			printf("����Ϊ��a[%d][%d]=%d\n", n, m, a[n][m]);
			break;
		}
	}
	if (temp == 0)
		printf("�ö�ά���鲻���ڰ��㣡");
}

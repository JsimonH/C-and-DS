#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

/*���Ͼ��� 
��һ����ά����. 
�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����. 
�������������в���һ�������Ƿ���ڡ� 
ʱ�临�Ӷ�С��O(N)*/

int Reseach(int arr[][3], int row, int col, int num)
{
	int i = 0;
	int j = col - 1;
	//�ӵ�һ��,���һ�п�ʼѰ��
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
	printf("��������Ҫ���ҵ�����:>\n");
	scanf("%d", &target);
	int ret=Reseach(arr, row, col, target);
	if (ret==1)
		printf("�ҵ���!\n");
	else
		printf("û�ҵ�!\n");
	return 0;
}

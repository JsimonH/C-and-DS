/*
InsertSort and ShellSort
*/

#include<stdio.h>

void Print(int* a, int n) //打印排序结果
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	//多趟排序
	for (int i = 0; i < n - 1; i++)
	{
		//单趟排序
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end+1] = tmp;
	}
}

void ShellSort(int*a, int n)
{
	//gap > 1时为预排序
	//gap = 1时为直接插入排序
	int gap = n;
	while (gap > 1)
	{
		//间隔为gap的预排序
		gap = gap / 3 + 1;   //保证最后一次一定是1
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

int main()
{
	int arr[] = { 3,6,2,5,7,9,8,6,1,4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	
	InsertSort(arr, size);  //插入排序
	
	ShellSort(arr, size);   //希尔排序
	
  Print(arr,size);
	return 0;
}

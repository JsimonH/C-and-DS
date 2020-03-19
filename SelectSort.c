//SelectSort

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int*a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//在[begin,end]选出一个最大的和最小的下标
		int mini = begin, maxi = end;
		for (int i = begin; i <= end; i++)
		{
			if (a[i]>a[maxi])
				maxi = i;
			if (a[i] < a[mini])
				mini = i;
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
			maxi = mini;
		Swap(&a[end], &a[maxi]);
		
		begin++;
		end--;
	}
}

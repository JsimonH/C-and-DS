/*Given an array of integers nums, sort the array in ascending order.

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
*/

void Swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int Hoare(int* a, int begin, int end)
{
	// end做key，左边先走 / begin做key，右边先走
	int key = a[end];
	int keyindex = end;
	while (begin < end)
	{
		// begin找大
		while (begin < end && a[begin] <= key)
			++begin;

		// end找小
		while (begin < end && a[end] >= key)
			--end;

		Swap(&a[begin], &a[end]);
	}

	Swap(&a[begin], &a[keyindex]);

	return begin;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	int keyindex = Hoare(a, begin, end);
	// [begin, keyindex-1]  key  [keyindex+1,end]
	QuickSort(a, begin, keyindex - 1);
	QuickSort(a, keyindex + 1, end);
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    QuickSort(nums, 0, numsSize-1);
    *returnSize = numsSize;
    return nums;
}

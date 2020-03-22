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

int PrevCur(int* a, int begin, int end)
{
	int prev = begin - 1;
	int cur = begin;
	int key = a[end];

	while (cur < end) // 遇到key的位置就结束了
	{
		if (a[cur] < key && ++prev != cur)
        Swap(&a[prev], &a[cur]);
        ++cur;
    }
    ++prev;
	Swap(&a[prev], &a[end]);

	return prev;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	int keyindex = PrevCur(a, begin, end);
	// [begin, keyindex-1]  key  [keyindex+1,end]
	QuickSort(a, begin, keyindex - 1);
	QuickSort(a, keyindex + 1, end);
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    QuickSort(nums, 0, numsSize-1);
    *returnSize = numsSize;
    return nums;
}

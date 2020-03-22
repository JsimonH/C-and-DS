/*Given an array of integers nums, sort the array in ascending order.

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]

*/

int DigHole(int* a, int begin, int end)
{
	int key = a[end];
	while (begin < end)
	{
		// 找大
		while (begin < end && a[begin] <= key)
			++begin;
		a[end] = a[begin]; // 找到大扔到右边的坑里面去,同时end形成新的坑

		while (begin < end && a[end] >= key)
			--end;
		a[begin] = a[end]; // 找到小扔到左边的坑里面去，同时begin形成新的坑
	}

	a[begin] = key;
	return begin;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	int keyindex = DigHole(a, begin, end);
	// [begin, keyindex-1]  key  [keyindex+1,end]
	QuickSort(a, begin, keyindex - 1);
	QuickSort(a, keyindex + 1, end);
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    QuickSort(nums, 0, numsSize-1);
    *returnSize = numsSize;
    return nums;
}

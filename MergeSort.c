/*给定一个整数数组 nums，将该数组升序排列。

输入：[5,1,1,2,0,0]
输出：[0,0,1,1,2,5]

*/

void MergeSort(int* a, int begin, int end, int* tmp)
{
    if(begin >= end)
      return;
    // 先划分
    int mid = (begin + end) >> 1;
    // [begin, mid][mid+1,end] 无序
    MergeSort(a, begin, mid, tmp);
    MergeSort(a, mid+1, end, tmp);
    
    // [begin, mid][mid+1,end] 有序
	// 归并两段有序区间
    int begin1 = begin, end1 = mid;
    int begin2 = mid+1, end2 = end;
    int index = begin;
    while(begin1 <= end1 && begin2 <= end2)
    {
        if(a[begin1] < a[begin2])
          tmp[index++] = a[begin1++];
        else
          tmp[index++] = a[begin2++];
    }

    if (begin1 <= end1)
	{
		while (begin1<=end1)
			tmp[index++] = a[begin1++];
	}
	else
	{
		while (begin2 <= end2)
			tmp[index++] = a[begin2++];
	}
    // 将归并到tmp的数据归并回原数组
    memcpy(a+begin, tmp+begin, sizeof(int)*(end-begin+1));
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    int* tmp =(int*)malloc(sizeof(int) * numsSize);
    MergeSort(nums, 0, numsSize-1, tmp);
    free(tmp);   
    *returnSize = numsSize;
    return nums;
}

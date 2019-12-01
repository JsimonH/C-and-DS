#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
int cmp(const void *p1, const void *p2)
{
	return *(int *)p1 - *(int *)p2;
}

int removeDuplicates(int* nums, int numsSize){
	qsort(nums, numsSize, sizeof(int), cmp);
	int ret = 0;
	for (int i = 0; i < numsSize; i++) {
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		nums[ret] = nums[i];
		ret++;
	}
	return ret;
}
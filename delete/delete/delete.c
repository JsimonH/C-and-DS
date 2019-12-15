/*给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。*/

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

#define _CRT_SECURE_NO_WARNINGS 1

int removeElement(int* nums, int numsSize, int val)//删除数组的重复元素
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] != val)//如果不相等就跳出这次循环
		{
			continue;
		}
		if (nums[i] == val)//相等与数组最后一个元素交换
		{
			tmp = nums[i];
			nums[i] = nums[numsSize - 1];
			nums[numsSize - 1] = tmp;
			if (nums[numsSize - 1] == val)//如果最后一个数字也等于val让循环i--
			{
				i--;
			}
			numsSize--;
		}
	}
	return numsSize;
}
/*给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。*/

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

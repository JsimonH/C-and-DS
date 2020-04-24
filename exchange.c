/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。
*/

int* exchange(int* nums, int numsSize, int* returnSize){
    int* ret = (int*)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    int i, j = 0, k = numsSize - 1;
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] % 2 == 1)
        {
            ret[j] = nums[i];
            j++;
        }
        else
        {
            ret[k] = nums[i];
            k--;
        }
    }
    return ret;
}

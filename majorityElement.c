/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
*/

int majorityElement(int* nums, int numsSize){
    int count = 0, num = 0;
    for(int i = 0 ; i < numsSize ; i++)
    {
        if(count == 0)
        {
            num = nums[i];
            count++;
        }
        else
            (num == nums[i]) ? count++ : count--;
    }
    return num;
}

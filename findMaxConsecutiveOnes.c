/*Given a binary array, find the maximum number of consecutive 1s in this array.
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
*/


int findMaxConsecutiveOnes(int* nums, int numsSize){
    int max = 0;     // 保存当前最大连续1的个数
    int count = 0;   // 保存当前连续1的个数
    //遍历数组，如果为1，count++，如果为0，比较当前count与max的值，较大的保存到max，然后count清零，继续遍历
    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] == 1)
            count++;
        else
        {
            max = max > count ? max : count;
            count = 0;
        }
    }
    max = max > count ? max : count;
    return max;
}

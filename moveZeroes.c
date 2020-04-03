/*Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

*/

void moveZeroes(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0)
        return;

    int slow = 0;
    int fast = 0;

    for (int i = 0; i < numsSize; i++) 
    {
        if (nums[fast] != 0 )
        {
            nums[slow++] = nums[fast++];
        }
        else 
        {
            fast++;
        }
    }

    while(slow < numsSize) 
    {
        nums[slow++] = 0;
    }
    return;
}

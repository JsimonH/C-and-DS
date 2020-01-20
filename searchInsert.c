/*给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。
example:
input:[1,3,5,6], 5
output:2
input:[1,3,5,6], 2
output:1  */

int searchInsert(int* nums, int numsSize, int target){
    if(numsSize==0) return 0;
    int low=0,high=numsSize-1,index=numsSize/2;
    while(low<high)
    {
        if(target==nums[index]) return index;
        if(target>nums[index]) low=index+1;
        else high=index-1;
        index=(high+low)/2;
    }
    if(target>nums[index]) return index+1;
    return index;
}

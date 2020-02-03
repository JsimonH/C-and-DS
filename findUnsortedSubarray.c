/*给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
你找到的子数组应是最短的，请输出它的长度。
input: [2, 6, 4, 8, 10, 9, 15]
output: 5
explain: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。*/

int findUnsortedSubarray(int* nums, int numsSize) {
    int i=0,j=numsSize-1;
    int left=-1,right=-1;
    for(i;i<numsSize-1;i++){
        for(int k=i+1;k<numsSize;k++){
            if(nums[i]>nums[k]){
                left=i;
                break;
            }
        }
         if(left!=-1)
                break;
    }
    if(i==numsSize-1)
        return 0;
    for(j;j>0;j--){
        for(int m=j-1;m>=0;m--){
            if(nums[j]<nums[m]){
                right=j;
                break;
            }
        }
        if(right!=-1)
            break;
    }
    return right-left+1;
    
}

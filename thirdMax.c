/*给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。*/

int thirdMax(int* nums, int numsSize){
int i,j;
    int a1,a2,a3;
    a1=nums[0];
    a2=a1;
    for(i=0;i<numsSize;i++){
         if(nums[i]>a1)
            a1=nums[i];
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]<a1 && (nums[i]>a2 || a1==a2))
            a2=nums[i];
    }
    a3=a2;
    for(i=0;i<numsSize;i++){
        if(nums[i]<a2 && (nums[i]>a3 || a2==a3))
            a3=nums[i];
    }
    return a2!=a3?a3:a1;
}

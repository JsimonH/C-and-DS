/*Find the Duplicate Number
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least 
one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Input: [1,3,4,2,2]
Output: 2

Input: [3,1,3,4,2]
Output: 3
*/

int findDuplicate(int* nums, int numsSize){
    int l = 0, h = numsSize - 1;
     while (l <= h) 
     {
         int mid = (l + h) / 2;
         int cnt = 0;
         for (int i = 0; i < numsSize; i++) 
         {
             if (nums[i] <= mid) 
                cnt++;
         }
         if (cnt > mid) 
            h = mid - 1;
         else 
            l = mid + 1;
     }
     return l;
}

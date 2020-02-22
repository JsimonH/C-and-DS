/*Find Minimum in Rotated Sorted Array
Input: [3,4,5,1,2],
Output: 1
*/

int findMin(int* nums, int numsSize){
    int l = 0, h = numsSize - 1;
    while (l < h) {
        int m = l + (h - l) / 2;
        if (nums[m] <= nums[h]) {
            h = m;
        } else {
            l = m + 1;
        }
    }
    return nums[l];
}

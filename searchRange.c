/*给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。*/

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
int *returnnums = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    returnnums[0] = -1;
    returnnums[1] = -1;
    if (numsSize <= 0) return returnnums;
    int l = 0, r = numsSize - 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (nums[mid] == target) {
            int index = mid;
            while (index > 0 && nums[index] == nums[index - 1]) index--;
            returnnums[0] = index;
            index = mid;
            while (index < numsSize - 1 && nums[index] == nums[index + 1]) index++;
            returnnums[1] = index;
            break;
        }
        if (nums[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return returnnums;
}

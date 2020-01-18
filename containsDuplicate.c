/*给定一个整数数组，判断是否存在重复元素。
如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。*/

bool containsDuplicate(int *nums, int numsSize) {
    int i, j, tmp;
    for (i = 1; i < numsSize; i++) {
        tmp = nums[i];
        for (j = i - 1; j >= 0; j--) {
            if (nums[j] == tmp) {
                return true;
            } else if (nums[j] < tmp) {
                nums[j + 1] = tmp;
                break;
            } else {
                nums[j + 1] = nums[j];
            }   
        }   
    }   
    return false;
}

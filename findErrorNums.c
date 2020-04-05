/*Set Mismatch
The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set 
got duplicated to another number in the set, which results in repetition of one number and loss of another number.Given an array 
nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find 
the number that is missing. Return them in the form of an array.

Input: nums = [1,2,2,4]
Output: [2,3]
*/

int* findErrorNums(int* nums, int numsSize, int* returnSize){
    *returnSize = 2;
    int hash[numsSize + 1];
    memset(hash, 0,sizeof(int) * (numsSize + 1));
    int *answer = malloc(sizeof(int) * 2);
    memset(answer, 0, sizeof(int) * 2);

    for (int i = 0; i < numsSize; i++) {
        hash[nums[i]]++;
    }
    for (int i = 0; i < numsSize; i++) {
        if (hash[nums[i]] == 2) {
            answer[0] = nums[i];
        }
    }
    for (int i = 1; i < numsSize + 1; i++) {
        if (hash[i] == 0) {
            answer[1] = i;
        }
    }
    return answer;
}

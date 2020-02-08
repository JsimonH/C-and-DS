/*Input: numbers={2, 7, 11, 15}, target=9
  Output: index1=1, index2=2
使用双指针，一个指针指向值较小的元素，一个指针指向值较大的元素。指向较小元素的指针从头向尾遍历，指向较大元素的指针从尾向头遍历。
如果两个指针指向元素的和 == target，那么得到要求的结果；
如果 和 > target，移动较大的元素，使和变小一些；
如果 和 < target，移动较小的元素，使和变大一些。*/

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int index1=0;
    int index2=numbersSize-1;
    *returnSize=2;
    while(index1<index2)
    {
        if(numbers[index1]+numbers[index2]==target)
        {
           break;
        }
        else if(numbers[index1]+numbers[index2]<target)
        {
            index1++;
        }
        else{
            index2--;
        }
    }
    int* arr=(int*)malloc(sizeof(int)*2);
    arr[0]=index1+1;
    arr[1]=index2+1;
    return arr;
}

/*给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。
你可以返回满足此条件的任何数组作为答案。
example：
input：[3,1,2,4]
output：[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。*/

int* sortArrayByParity(int* A, int ASize, int* returnSize){
int *result = (int *)malloc(sizeof(int)*ASize); 
int evenIndex = 0;
int unEvenIndex = ASize-1;
*returnSize = ASize;
for(int i = 0; i < ASize; i++)
{
    if(A[i]%2==0)
    {
        result[evenIndex] = A[i];
        evenIndex++;
    }
    else
    {
        result[unEvenIndex]=A[i];
        unEvenIndex--;
    }
    if(evenIndex>unEvenIndex)
        break;
}
return result;
}

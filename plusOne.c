/*给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。
input: [1,2,3]
output: [1,2,4]
explain: 输入数组表示数字 123。*/

int* plusOne(int* digits, int digitsSize, int* returnSize){
 for(int i=digitsSize-1;i>=0;--i)
    {
        digits[i] = (digits[i]+1)%10;
        if(digits[i]!=0)    break;
    }
    *returnSize = digitsSize;
    if(digits[0]==0)
    {
        int *result = (int*)malloc(sizeof(int)*(digitsSize+1));
        result[0] = 1;
        for(int k=1;k<digitsSize+1;++k)
            result[k] = 0;
        *returnSize = digitsSize+1;
        return result;
    }
    else
        return digits;
}

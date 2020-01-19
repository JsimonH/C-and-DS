/*给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
example：
input：[-4,-1,0,3,10]
output：[0,1,9,16,100]*/

void Quicksort(int* num,int left,int right){
    if(left>=right)
        return;
    int key=num[left];
    int i=left,j=right;
    while(i<j){
        while(i<j&&num[j]>=key)
            j--;
        num[i]=num[j];
        while(i<j&&num[i]<=key)
            i++;
        num[j]=num[i];
    }
    num[i]=key;
    Quicksort(num,left,i-1);
    Quicksort(num,i+1,right);
}
int* sortedSquares(int* A, int ASize, int* returnSize) {
    * returnSize=ASize;
    int* result=malloc(sizeof(int)*ASize);
    int i,temp;
    for(i=0;i<ASize;i++){
        result[i]=A[i]*A[i];
    }
    Quicksort(result,0,ASize-1);
    return result;
}

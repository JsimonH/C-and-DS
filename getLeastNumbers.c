/*
输入整数数组 arr ，找出其中最小的 k 个数。例如，k = 4, 输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

输入：arr = [0,1,2,1], k = 1
输出：[0]
*/

void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int* arr, int start, int end)
{
    int key = arr[start];
    while(start < end)
    {
        while(start < end && arr[end] >= key)
            end--;

        if(start < end)
            arr[start++] = arr[end];

        while(start < end && arr[start] <= key)
            start++;

        if(start < end)
            arr[end--] =  arr[start];
    }
    arr[start] = key;
    return start;
}

int* quickSort(int* arr, int start, int end, int k)
{
    if(start < end)
    {
        int mid = partition(arr, start, end);
        if(mid == k)
        {
            return arr;
        }
        if(mid > k)
        {
            return quickSort(arr, start, mid, k);
        }
        if(mid < k)
        {
            return quickSort(arr, mid + 1, end, k);
        }
    }
    return arr;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    *returnSize = k;
    return quickSort(arr, 0, arrSize -1, k);
}

/*Given an array of integers nums, sort the array in ascending order.

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
*/

void Swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void AdjustDown(int* a, int n, int root)
{
    int parent = root;
    int child = parent * 2 + 1;
    while(child < n)
    { 
        //找出左右孩子中大的那个
        if(child + 1 < n && a[child] < a[child+1])
        {
            child++;
        }
        
        //如果孩子比父亲大,交换,继续向下调整
        if(a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int* a, int n)
{
    //升序建大堆
    for(int i = (n-1-1)/2; i>=0; i--)
    {
        AdjustDown(a, n, i);
    }

    int end = n-1;
    while(end > 0)
    {
        //把堆顶当前最大数依次换到最后
        Swap(&a[0], &a[end]);
        //调堆选出剩下的数当中最大
        AdjustDown(a, end, 0);
        end--;
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    HeapSort(nums, numsSize);
    *returnSize = numsSize;
    return nums;
}

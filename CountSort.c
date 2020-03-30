void CountSort(int* a, int n)
{
    int max = a[0], min = a[0];
    for(int i = 0; i < n; i++)
    {
         if(a[i] > max)
            max = a[i];
        
         if(a[i] < min)
            min = a[i];
    }
    int range = max - min + 1;
    int* countArr = (int*)malloc(range*sizeof(int));
    memset(countArr, 0, sizeof(int)*range);
    //1.统计次数
    for(int i = 0; i < range; i++)
    {
        countArr[a[i] - min]++;
    }
    //2.根据次数进行排序
    int j = 0;
    for(int i = 0; i < range; i++)
    {
        while(countArr[i]--)
        {
            a[j++] = i + min;
        }
    }
} 

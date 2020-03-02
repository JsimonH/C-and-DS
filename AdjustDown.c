/*向下调整算法*/

void AdjustDown(int* a, int n, int root)
{
   int parent = root;
   int child = parent*2+1;
   while(child < n)
   {
      if(child+1 < n && a[child+1] < a[child])
      {
         child++;
      }
      
      if(a[parent] > a[child])
      {
        int tmp = a[parent];
        a[parent] = a[child];
        a[child] = tmp;
        
        parent = child;
        child = parent*2+1;
      }
      
      else
      break;
   }
}

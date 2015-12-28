#include<stdio.h>

long long int disordernu = 0;
int temp1[2000000];
int partition(int array[],int array1[], int low, int high)
{
    int pv = array[low];
    int temp;
    while( low < high )
    {
        while( (low < high) && (array[high] >= pv) )
        {
            high--;
        }
         temp = array[low];
         array[low] = array[high];
         array[high] = temp;
         temp = array1[low];
         array1[low] = array1[high];
         array1[high] = temp;
        while( (low < high) && (array[low] <= pv) )
        {
            low++;
        }
        
         temp = array[low];
         array[low] = array[high];
         array[high] = temp;
         temp = array1[low];
         array1[low] = array1[high];
         array1[high] = temp;
    }
    
    return low;
}
void QSort(int array[], int array1[], int low, int high)
{
    if( low < high )
    {
        int pivot = partition(array,array1,low, high);
        
        QSort(array,array1, low, pivot-1);
        QSort(array,array1, pivot+1, high);
    }
}

void disorder(int *a, int p, int q,int r)
{
   int i,j,k;     
   int n1 = q-p+1;
   int n2 = r-q;
   for(i = 0; i < n1; i++)
   {
     temp1[i] = a[p+i];      
   }
   i = 0;
   j = 0;
   for(k = p;((i < n1)||(j < n2)); k++)
   {
         if((i < n1)&&(!(j < n2) || temp1[i] <= a[q+j+1]))
         {
             a[k] = temp1[i];
             i++;      
         }
         else
         {
           a[k] = a[q+j+1];
           disordernu = disordernu + n1 - i;
           j++;   
         }
   }
     
}

void disordersum(int *a, int p, int r)
{
  if(p < r)
  {
    int q =(p + r)/2;
    disordersum(a, p, q);
    disordersum(a, q+1, r); 
    disorder(a, p, q, r); 
  }
     
}
int main()
{
   int i,*a,*b;
   long long int n,sum = 0;
   scanf("%d",&n);
   sum = n*(n-1)/2;
   a = (int *)malloc(4*n);
   b = (int *)malloc(4*n);
   for(i = 0; i < n; i++)
   {
     scanf("%d%d",&(a[i]),&(b[i]));     
   }
   
   QSort(a, b, 0, n-1);
   disordersum(b, 0, (n-1));
   printf("%lld\n",(sum - disordernu));
   return 0;
}

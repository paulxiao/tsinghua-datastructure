#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct _tag_elem
{
    long long int  num;
    char a[9];        
}elem;


int  Dic_order(char *a, char *b)
{
    int i = 0;
    while(a[i] != '\0' && b[i] != '\0')
    {
          if(a[i] < b[i])
          {
             return 1;        
          }
          if(a[i] > b[i])
          {
            return 0;        
          } 
          i++;          
    } 
    if(a[i] == '\0')
    {
       return 1;        
    }
    if(b[i] == '\0')
    {
      return 0;        
    }
     
}
void MIN_Heapify(elem *heap, int j,int n)
{
   int l = j*2+1;
   int r = j*2+2;
   int min = 0;
  // printf("l = %d\n",l);
  // printf("ln = %d\n",((elem *)heap[l])->num);
  // printf("jn = %d\n",((elem *)heap[j])->num);
   if(l < n && (((heap[l]).num <(heap[j]).num) || 
       ((heap[l]).num ==(heap[j]).num &&  Dic_order((heap[l]).a, (heap[j]).a) == 1 ))  )
   {
        // printf("ln = %ld\n",((elem *)heap[l])->num);
        // printf("jn = %ld\n",((elem *)heap[j])->num);
         min = l;
         //printf("excute0!\n");   
   }
   else 
   {
      
            min = j;   
   }
   if(r < n && ((heap[r]).num < (heap[min]).num  || 
       ((heap[r]).num ==(heap[min]).num &&  Dic_order((heap[r]).a, (heap[min]).a) == 1)))
   {
        min = r;
        // printf("excute3!\n");      
   }
   
  // printf("min = %d\n",min);
   if(min != j)
   {
       elem temp = heap[j];
       heap[j] = heap[min];
       heap[min] = temp;
       MIN_Heapify(heap, min,n);       
   }
   
}

void Build_Minheap(elem *heap, int n)
{
    int  i = 0;
    for(i = (n-2)/2; i >= 0; i--)
    {
        MIN_Heapify(heap,i,n);  
    }      
}

elem task[4000000];
int main()
{
    int m = 0, n = 0;
    int i = 0;
    int j = 0;
    setvbuf(stdin,(char*)malloc(1<<20),_IOFBF,1<<20);
    setvbuf(stdout,(char*)malloc(1<<20),_IOFBF,1<<20);
    scanf("%d %d",&n,&m);
    for(i = 0; i < n; i++)
    {
       scanf("%lld %s",&(task[i].num),task[i].a);
    }
   
    
    
     Build_Minheap(task, n);
     
      for(i = 0; i < m && n > 0; i++)
     {
          
          printf("%s\n",task[0].a);
          task[0].num = task[0].num << 1;
          if(task[0].num >= 4294967296 )
          {
             elem temp = task[0];
             task[0] = task[n-1];
             task[n-1] = temp;
             n = n-1;
          }
          MIN_Heapify(task, 0,n);
     }
     /*
     for(i = 0; i < n; i++)
     {
         printf("%d ",task[i].num);
         printf("%s\n",task[i].a); 
     }
    */
    system("pause");
    return 0;    
}

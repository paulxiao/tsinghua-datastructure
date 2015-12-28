#include<stdio.h>


int main()
{
  int total = 0;
  char instruct;
  int height = 0;
  int *Tqueue = NULL;
  int *result = NULL;
  int i = 0, j = 0,k = 0;
  int num = 0;
  
  int m = 0,l = 0,se = 0, temp = 0;
  setvbuf(stdin,(char*)malloc(1<<20),_IOFBF,1<<20);
  setvbuf(stdout,(char*)malloc(1<<20),_IOFBF,1<<20);
  scanf("%d",&total);
  Tqueue = (int *)malloc(total*4);
  result = (int *)malloc(total*4);
  while(num < total)
  {
       scanf("\n%c",&instruct);
       if(instruct == 'E')
       {
          scanf("%d",&Tqueue[i]);
          i++;            
       }
       else if(instruct == 'D')
       {
          result[k] = Tqueue[j];
          k++;
          j++;
           
       }
       else if(instruct == 'M')
       {
           if(l > j)
           {
              for(se = m; se < i; se++)
              {
                  if(Tqueue[se] > temp)
                  {
                     temp = Tqueue[se];
                  }
              }
              result[k] =  temp;
              m = i; 
           }
           else 
           {
               temp = 0;
               m = i;
               for(se = j; se < i;se++)
               {
                   if(Tqueue[se] > temp)
                   {
                      temp = Tqueue[se];
                      l = se;
                   }
               }
               result[k] =  temp;
               
           }  
           k++;
          
       }
       num++;                            
  } 
  for(i = 0; i < k;i++)
  {
    printf("%d\n",result[i]);      
  } 
  system("pause");  
  return 0; 
} 

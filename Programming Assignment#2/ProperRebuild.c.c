#include<stdio.h>

void recons(int* pre, int *pos,int prei, int prej, int posi, int posj)
{
  int i = 0, j = 0;
  if(prei + 2 < prej)
  {
      for(i = prei; i <= prej; i++)
      {
           if(pre[i] == pos[posj-1])
              break;   
      }
      for(j = posi; j <= posj; j++)
      {
           if(pre[prei+1]==pos[j])
           {
             break;                       
           }      
      }
     recons( pre, pos,prei+1, i-1, posi, j);          
  }
  if(prei < prej)
  {
    
    if(prei + 2 == prej)
    {
     printf("%d ",pre[prei+1]);
     printf("%d ",pre[prei]);
     printf("%d ",pre[prei+2]);     
    }
    else 
    {
       
      
      if(pos[posi] == pre[prei+1])
      {
          printf("%d ",pre[prei+1]);          
      }
      printf("%d ",pre[prei]);
      if(pos[posj-1] == pre[prej])
      {
          printf("%d ",pos[posj-1]);
      }  
    }
  }
  if(prei + 2 < prej)
  {
     recons( pre, pos,i, prej, j+1, posj-1);     
  }     
}
int main()
{
  int total = 0;
  int *pre = NULL;
  int *pos = NULL;
  int i = 0;
  setvbuf(stdin,(char*)malloc(1<<20), _IOFBF, 1<<20);
  setvbuf(stdout,(char*)malloc(1<<20), _IOFBF, 1<<20);
  scanf("%d",&total);
  pre = (int *)malloc(4*total);
  pos = (int *)malloc(4*total);
  for(i = 0; i < total; i++)
  {
    scanf("%d",&pre[i]);      
  }
  for(i = 0; i < total; i++)
  {
    scanf("%d",&pos[i]);      
  }
  if(total == 1)
  { 
     printf("%d",pre[0]);
  }
  else
  {
     recons(pre, pos,0, total-1, 0, total-1);
  }
  return 0;    
}

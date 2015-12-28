#include<stdio.h>
#include<string.h>
#include<malloc.h>

int* getnext(char *p)
{
     int m = strlen(p);
     int *N = (int *)malloc(sizeof(int)*m);
     int j,k;
     N[0] = -1;
      k = -1;
      j = 0;
      while(j < m-1)
      {
          if(k == -1 || p[j] == p[k])
          {
              ++j;
              ++k;
              N[j] = k;
              
          }
          else
          {
              k = N[k];
          }
      }
      return N;
}

int match(char* T, char *P)
{
  int *next =  getnext(P);
  int sLen = strlen(T);
  int pLen = strlen(P);
  int i,j;
  i = 0;
  j = 0;
  while(i < sLen && j < pLen)
  {
      if(T[i] == P[j] || j == -1)
      {
            i++;
            j++;
      }
     else
     {
        j = next[j];
     }
  }
  free(next);
  if(j == pLen)
     return i-j;
  else
    return -1;
}

int main()
{
    char *s1, *s2;
    char *T,*P;
    int *next;
    int  l1,l2;
    s1 = (char*)malloc(100001);
    s2 = (char*)malloc(100001);
    
    setvbuf(stdin,(char*)malloc(1<<20),_IOFBF,1<<20);
    setvbuf(stdout,(char*)malloc(1<<20),_IOFBF,1<<20);
    
    while(scanf("%s %s",s1,s2) != EOF)
    {
        l1 = strlen(s1);
        l2 = strlen(s2);
        if(l1 != l2)
        {
          
           printf("NO\n");
              
        }
        else
        {
           T = (char*)malloc(2*l1+1);
           P = (char*)malloc(l2+1);
           strcpy(T,s1);
           strcpy(P,s2);
           strcat(T,s1);
           //printf("%s %s\n",T,P);
           
           if(match(T, P) == -1)
           {
             
              printf("NO\n");
                     
           }
           else
           {
                
                printf("YES\n");
                
           } 
           free(T);
           free(P);    
        }
                          
    }
    
    system("pause");
    return 0;    
}

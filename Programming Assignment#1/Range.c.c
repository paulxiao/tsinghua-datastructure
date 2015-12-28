#include<stdio.h>
#include<malloc.h>
int S[10000002] = {0};
int main(void)
{
 int i,j,l = 0,k = 0;
 int m,n;
 int s, *a, *b;
 scanf("%d %d",&n,&m);
 a = (int *)malloc(m*sizeof(int));
 b = (int *)malloc(m*sizeof(int));
 for(i = 0; i < n; i++)
 {
    scanf("%d",&s); 
    S[s] = 1;      
 } 
 for(j = 0; j < m; j++)
 {
    scanf("%d%d",&(a[j]),&(b[j]));     
 }
 for(i = 10000000; i >= 0;i--)
 {
   if(S[i] == 1)
   {
       k = k+1;     
   } 
   S[i] = k; 
      
 }
 
 for(i = 0; i < m; i++)
 {
    k = b[i]+1;
    j = a[i];
    l = S[j]-S[k];
    printf("%d\n",l);
 }
 return 0;   
}

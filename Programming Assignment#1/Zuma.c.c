#include<stdio.h>
#include<malloc.h>
#define MaxSize 20001
typedef struct
{
  char data;
  int next;
  int prev;       
}colorlist;
colorlist sta[MaxSize];

int spare = 0;
int length = 0;
void create()
{
   int i;
   spare = 1;
   for(i = 0;i < (MaxSize-1);i++)
   	{
       sta[i].next = i+1;
       sta[i].prev = i-1;
	   sta[i].data = '-';
    }
    sta[MaxSize-1].next= -1;
    sta[0].next = 0;
}

int insert( int pos,char p)
{
   int i,j,k;
   
   if(pos > 0 && pos < MaxSize)
   	{

	   k = sta[0].next;
       i = spare;
       spare = sta[spare].next;
       sta[i].data = p;
	   for(j = 1;j < pos-1;j++)
	   {
            k = sta[k].next;
	   }
	   if(pos == 1)
	   	{
                k = 0;
	    }
       if(sta[k].next != 0)
	   {
	      sta[sta[k].next].prev = i;
       }
	   sta[i].next = sta[k].next;
	   sta[i].prev = k;
	   sta[k].next = i;
	   length = length + 1;
	   return 1;
    }
    else 
    {
	   return 0;
	}
}
void delete_color()
{
    int i,l,k = 0,m = 0;
    int current1;
    k = sta[0].next;
    for(i = 1; (i <= length) && (k != 0);i++)
    {
        if(sta[k].next != 0 && sta[k].data == sta[sta[k].next].data)
        {
             m++;
            // printf("m = %d\n",m);
        }
        else
        {
          if(m > 1 )
          {
             for(l = 0; l <= m && k != 0; l++)
             {
              //printf("k = %d\n",k);
             current1 = sta[k].prev;
             sta[sta[k].prev].next = sta[k].next;
             if(sta[k].next != 0)
             {
               sta[sta[k].next].prev = sta[k].prev;
             } 
             length = length-1;
             k = current1; 
             }
             delete_color();
          }     
          m = 0;    
        } 
        k = sta[k].next;
   }
}
int main()
{
    
    char a,re1,re2;
    int i = 1,j=0,k;
    int n;
    int *b;
    char *c;
    create();
    
    while(scanf("%c",&a)&&(a != '\n'))
    {
      insert(i,a);
      i++;
                       
    } 
    /*
     k = sta[0].next;
     for(i = 1;i <= length;i++)
     {
        printf("%c %d %d\n",sta[k].data,sta[k].next,sta[k].prev);
        k = sta[k].next;
     }
     */
    scanf("%d",&n);
    b = (int *)malloc(n*sizeof(int));
    c = (char *)malloc(n*sizeof(char)); 
    for(j = 0; j < n; j++)
    {
        scanf("%d%c%c%c",&(b[j]),&re1,&(c[j]),&re2);     
    }
     
    for(j = 0;j < n; j++)
    {
     
      
            insert(b[j]+1,c[j]);
            delete_color();
            k = sta[0].next;
            if( length == 0)
            {
               printf("-");     
            }
            else
            {
               for(i = 1;i <= length;i++)
               {
                  printf("%c",sta[k].data);
	              k = sta[k].next;
               }
            }
           printf("\n");
     }
     
    free(b);
    free(c);
    //system("pause");
    return 0;
}

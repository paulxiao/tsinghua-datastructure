#include<stdio.h>

typedef struct _tag_Edge  Edge;
struct _tag_Edge
{
   int   nelem;
   Edge *next;
};

typedef struct _tag_Vertex
{
    int num;
    Edge header;        
}Vertex;
Vertex* init(int n)
{
   Vertex* ver = (Vertex *)malloc(sizeof(Vertex)*(n+1));
   int i = 0;
   if(ver)
   {
      for(i = 0; i < n+1; i++)
      {
          ver[i].num = 0;
          ver[i].header.next = NULL;
          ver[i].header.nelem = 0;      
      }          
   }
   return ver;     
}

void insert(int fr, int to, Vertex* ver)
{
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    if(edge)
    {
        edge->nelem = to;
        edge->next = ver[fr].header.next;
        ver[fr].header.next = edge;
        
    }
           
}

void maxnum(Vertex* ver, int fr)
{
    int i = 0;
    Edge *current = ver[fr].header.next; 
    for(current = ver[fr].header.next; current != NULL; current = current->next )
    {
         i = current->nelem;
         if(ver[i].num == 0)
         {
            maxnum(ver, i);
         }
         if(ver[i].num+1 > ver[fr].num)
         {
             ver[fr].num = ver[i].num+1;
         } 
        // printf("%d %d\n",fr,ver[fr].num);
          
    }  
}

int maxsum(Vertex* ver, int n)
{
   int i = 0;
   int max_num = 0;
   for(i = 1; i <= n; i++)
   {
        if(ver[i].num == 0)
        {
         maxnum(ver, i);            
        }   
   }
   for(i = 1; i <= n; i++)
   {
      if(ver[i].num > max_num)
      {
          max_num = ver[i].num;              
      }   
   }
   return (max_num+1);  
}
int main()
{
   
   Vertex* ver = NULL;
   int n,m;
   int fr,to;
   int i = 0;
   int sum = 0;
   
   setvbuf(stdin,(char*)malloc(1<<20),_IOFBF,1<<20);
   setvbuf(stdout,(char*)malloc(1<<20),_IOFBF,1<<20);
  
   scanf("%d%d",&n,&m);
   ver = init(n);
   for(i = 0; i < m; i++)
   {
       scanf("%d%d",&fr,&to);
       insert(fr, to, ver);      
   }
   sum = maxsum(ver, n);
   printf("%d",sum);
  system("pause");
  return 0;  
}

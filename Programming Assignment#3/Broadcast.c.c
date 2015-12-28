#include<stdio.h>

//队列实现
int queue[10000];
int trail = 0;
int head = 0;

int result = 1;
void enqueue(int elem)
{
    
    queue[trail] = elem;
    trail++;       
}

int dequeue()
{  
   
   int ret = queue[head];
   head++;
   return ret;
     
}

//图实现 
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
    Edge* edge_l = (Edge*)malloc(sizeof(Edge));
    Edge* edge_r = (Edge*)malloc(sizeof(Edge));
    if(edge_l && edge_r)
    {
        
            edge_l->nelem = to;
            edge_l->next = ver[fr].header.next;
            ver[fr].header.next = edge_l;
            
            edge_r->nelem = fr;
            edge_r->next = ver[to].header.next;
            ver[to].header.next = edge_r;
            
              
    }
           
}

void Owresult(Vertex* ver, int fr)
{
    int elem = 0;
    Edge *current = ver[fr].header.next;
    if(ver[fr].num == 0)
    {
        ver[fr].num = 1;
        enqueue(fr);
    }
    
    int k = 20;
    while(trail != head)
    {
        int v = dequeue();
        
        for(current = ver[v].header.next; current != NULL; current = current->next )
        {
                
            elem = current->nelem;
                 
            if(ver[elem].num == 0)
            {
                enqueue(elem);
                ver[elem].num = -ver[v].num;
            }
            else if(ver[elem].num == ver[v].num) 
            {
               
                  result = -1;
                  break;        
            }
       }
       if(result == -1)
       {
          break;
       }
       
    } 
         
}

void Awresult(Vertex* ver, int n)
{
    int i = 0;
    for(i = 1; i <= n && result == 1; i++)
    {
          if(ver[i].num == 0)
          {
             Owresult(ver, i);           
          }
    } 
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
   Awresult(ver, n);
   printf("%d",result);
  system("pause");
  return 0;  
}

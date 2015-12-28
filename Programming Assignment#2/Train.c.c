#include<stdio.h>

typedef struct _tag_stack S_stack;
struct _tag_stack
{
    int capacity;
    int length;
    int  *array;
};
S_stack* stack_Create(int capacity)
{
  S_stack* Sstack =(S_stack*)malloc(sizeof(S_stack)+sizeof(int)*capacity);
  if(Sstack != NULL)
  {
     Sstack->capacity = capacity;
     Sstack->length = 0;
     Sstack->array = (int *)(Sstack + 1);         
  } 
  return Sstack;       
}

void stack_push(int num,void* stack)
{
   S_stack* Sstack = (S_stack*)stack;
   if(Sstack != NULL )
   {
        Sstack->array[Sstack->length] = num;
        Sstack->length++;     
   }    
}

int stack_pop(void* stack)
{
   S_stack* Sstack = (S_stack*)stack;
   int ret = -1;
   if(Sstack != NULL)
   {
      ret = Sstack->array[--Sstack->length];        
   } 
   return ret;  
}

void Stack_wash(S_stack* Outstack,S_stack* Midstack,S_stack* Instack,int Mlen,int *cacul)
{
   int i = 0;
   int j = 0;
   while(i < Instack->length)
   { 
        if((Midstack->length == 0) ||(Instack->array[i] != Midstack->array[Midstack->length-1]))
        {
            stack_push(stack_pop(Outstack),Midstack);
            cacul[j++] = 0; 
            if(Midstack->length > Mlen)
            {
              printf("No\n");
              break;                    
            }                   
        } 
        else if(Instack->array[i] == Midstack->array[Midstack->length-1])
        {
             stack_pop(Midstack);
             cacul[j++] = 1;
             i++;
        }
        if(Outstack->length == 0 && Instack->array[i] != Midstack->array[Midstack->length-1] && Midstack->length > 0) 
        {
           printf("No\n");
           break; 
        }
   }
   if(i == Instack->length )
   {
       for(i = 0; i < 2*Instack->length;i++)
       {
          if(cacul[i] == 0)
          {
             printf("push\n");
          }
          else if(cacul[i] == 1)
          {
              printf("pop\n");  
          }
   }
   } 
}
int main()
{
  int Msize = 0;
  int Mlen = 0;
  int input = 0;
  int i = 0;
  int *cacul = NULL;
  setvbuf(stdin,(char*)malloc(1<<20),_IOFBF,1<<20);
  setvbuf(stdout,(char*)malloc(1<<20),_IOFBF,1<<20);
  scanf("%d%d",&Msize,&Mlen);
  S_stack* Outstack = stack_Create(Msize);
  S_stack* Midstack = stack_Create(Msize);
  S_stack* Instack = stack_Create(Msize);
  cacul = (int *)malloc(2*Msize*sizeof(int));
  
   for(i = 0; i < Msize; i++)
   {
          scanf("%d",&input);
          stack_push(input,Instack); 
   }
   for(i =  Msize; i >= 1; i--)
   {
      stack_push(i,Outstack);      
   }
   Stack_wash(Outstack,Midstack,Instack,Mlen,cacul);
   
   /*
   for(i = 0; i < 6;i++)
   {
       printf("%d ",Instack->array[i]);  
   }
   printf("the length is %d\n",Instack->length);
   printf("the capacity is %d\n",Instack->capacity);
   for(i = 0; i < 4;i++)
   {
       printf("%d ",stack_pop(Instack));  
   }
   printf("the length is %d\n",Instack->length);
   printf("the capacity is %d\n",Instack->capacity);
   
   
   printf("the length is %d\n",Outstack->length);
   printf("the capacity is %d\n",Outstack->capacity);
   for(i = 0; i < 4;i++)
   {
       printf("%d ",stack_pop(Outstack));  
   }
   printf("the length is %d\n",Outstack->length);
   printf("the capacity is %d\n",Outstack->capacity);
   */
   system("pause"); 
   return 0;
}

#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct _tag_Lnode Lnode;

struct _tag_Lnode
{
   char  usage;
   unsigned int adress;
   Lnode *next;
         
};

int ha[100003];
int main()
{
    int i = 0, j = 0, k = 0;
    int num = 0;
    unsigned int sum_str = 0;
    unsigned int index = 0;
    
    char* temp = NULL;
    Lnode* nodenum = NULL;
    
    char str[41];
    char* store[100040];
    
    setvbuf(stdin,(char*)malloc(1<<20),_IOFBF,1<<20);
    setvbuf(stdout,(char*)malloc(1<<20),_IOFBF,1<<20);
    for(i = 0; i < 100003; i++)
    {
        ha[i] = 1;      
    }
    
    scanf("%d\n",&num);
    for(i = 0; i < num; i++)
    {
         gets(str);
         for(j = 0; str[j] != '\0'; j++)
         {
            sum_str =  (sum_str<<5)|(sum_str>>27);
            sum_str += (int)str[j];  
         } 
         index = sum_str%100003;
         
         if(ha[index] == 1)
         {
             temp = (char *)malloc(strlen(str)+1);
             if(temp != NULL)
             {
                  strcpy(temp,str);
             }
             nodenum = (Lnode*)malloc(sizeof(Lnode));
             if(nodenum != NULL)
             {
                 nodenum->adress = (unsigned int)temp;
                 nodenum->next = NULL;
                 nodenum->usage = '0';
                 ha[index] = (int)nodenum;
             }
                           
         }
    
         else 
         {
              Lnode* current = (Lnode*)ha[index];
              Lnode* current1;
              
              while(current != NULL)
              {
                  if(strcmp( (char *)current->adress,str) == 0 && current->usage == '0')
                  {
                        store[k] =  (char *)current->adress;
                        current->usage = '1';
                        k++;
                        break;          
                  }
                  else if(strcmp( (char *)current->adress,str) == 0 && current->usage == '1')
                  {
                       break;
                  }
                  current1 = current; 
                  current = current->next;
                              
              } 
              
              if(current == NULL)
              {
                  char* temp = (char *)malloc(strlen(str)+1);
                  strcpy(temp,str);
             
                  Lnode* nodenum = (Lnode*)malloc(sizeof(Lnode));
                  nodenum->adress = (unsigned int)temp;
                  nodenum->next = NULL;
                  nodenum->usage = '0';
                  current1->next = (unsigned int)nodenum;        
              }   
              
         }
         sum_str = 0; 
    }
    
     for(i = 0; i < k; i++)
    {
         printf("%s\n",store[i]); 
    }
   
    system("pause");
    return 0;    
}

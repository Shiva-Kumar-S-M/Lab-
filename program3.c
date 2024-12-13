#include<stdio.h>
#include<stdlib.h>

int mutex=1;
int full=0;
int empty=10,x=0;

void producer()
{
     --mutex;
     ++full;
     --empty;
     x++;
     printf("\n Producer produces ""item %d",x);
     ++mutex;
}

void consumer()
{
      --mutex;
      --full;
      ++empty;
      printf("\n Consumer consumes ""item %d",x);
      x--;
      ++mutex;
}

int main()
{
      int n,i;
      printf("\n1. Press 1 for producer""\n2. Press 2 for consumer""\n3. Press 3 for exit");  
      for(i=1;i>0;i++)
      {
           printf("\n Enter your choice:");
           scanf("%d",&n);
           switch(n)
           {
                  case 1:if((mutex==1)&&(empty!=0))
                         {
                              producer();
                         }
                         else
                         {
                              printf("Buffer is full!");
                         }
                         break;
                  case 2:if((mutex==1)&&(full!=0))
                         {
                             consumer();
                         }
                         else
                         {
                             printf("Buffer is empty!");
                         }
                         break;
                  case 3:exit(0);
                         break;
            }
      }
}

                              
                  
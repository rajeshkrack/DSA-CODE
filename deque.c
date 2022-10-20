#include<stdio.h>
#include<conio.h>
#define MAX 50

int deque[MAX];
int left=-1, right=-1;

void inptdeque(void);
void outputdeque(void);


void insertright(void);
void insertleft(void);
void deleteright(void);
void deleteleft(void);
void displaydeque(void);

int main()
{
 int x ;
 do{
   printf("1.Input restricted deque\n");
  printf("2.Output restricted deque\n");
  printf("Enter your option 1 or 2 \n");
  scanf("%d",&x);
  switch(x){
    case 1:
    inputdeque();
    break;

    case 2:
    outputdeque();
    break;
  }

 }while(x<=2);
 
}




void inputdeque(){
    int i , option ;

    do {
        printf("______________INPUT RESTRICTED DEQUE__________________!!!");
        printf("\n1.Insert at right ");
        printf("\n2.Delete from left ");
        printf("\n3.Delete from right ");
        printf("\n5.Display ");
        printf("\n6.Quit");
        printf("\n\nEnter your option ");
        scanf("%d",option);
        switch(option){
            case 1:
            insertright();
            break;

            case 2:
            deleteleft();
            break;

            case 3:
            deleteright();
            break;

            case 4 :
            displaydeque();
            break;
        


        }

    }while(option<=4);
} 


void outputdeque(){
  int i , option ;

  do {
        printf("______________OUTPUT RESTRICTED DEQUE__________________!!!");
        printf("\n1.Insert at right ");
        printf("\n2.insert at left ");
        printf("\n3.Delete from left ");
        printf("\n5.Display ");
        printf("\n6.Quit");
        printf("\n\nEnter your option ");
        scanf("%d",option);
        switch(option){
            case 1:
            insertright();
            break;

            case 2:
            insertleft();
            break;

            case 3:
            deleteleft();
            break;

            case 4 :
            displaydeque();
            break;
        


        }

    }while(option<=4);


}



void insertright()
{
 int val;
 printf("\nEnter the value to be added ");
 scanf("%d",&val);
 if( (left==0 && right==MAX-1) || (left==right+1) )
 {
  printf("\nOVERFLOW");
 }
 if(left==-1)        
 {
  left=0;
  right=0;
 }
 else
 {
  if(right==MAX-1)
   right=0;
  else
   right=right+1;
 }
 deque[right]=val;
}


void insertleft()
{
 int val;
 printf("\nEnter the value to be added ");
 scanf("%d",&val);
 if( (left==0 && right==MAX-1) || (left==right+1) )
 {
  printf("\nOVERFLOW");
 }
 if(left==-1)        
 {
  left=0;
  right=0;
 }
 else
 {
  if(left==0)
   left=MAX-1;
  else
   left=left-1;
 }
 deque[left]=val;
}



void deleteright()
{
 if(left==-1)
 {
  printf("\nUNDERFLOW");
  return;
 }
 printf("\nThe deleted element is %d\n", deque[right]);
 if(left==right)          
 {
  left=-1;
  right=-1;
 }
 else
 {
  if(right==0)
   right=MAX-1;
  else
   right=right-1;
 }
}



void deleteleft()
{
 if(left==-1)
 {
  printf("\nUNDERFLOW");
  return;
 }
 printf("\nThe deleted element is %d\n", deque[left]);
 if(left==right)          
 {
  left=-1;
  right=-1;
 }
 else
 {
  if(left==MAX-1)
   left=0;
  else
   left=left+1;
 }
}



void displaydeque()
{
 int front=left, rear=right;
 if(front==-1)
 {
  printf("\nQueue is Empty\n");
  return;
 }
 printf("\nThe elements in the queue are: ");
 if(front<=rear)
 {
  while(front<=rear)
  {
   printf("%d\t",deque[front]);
   front++;
  }
 }
 else
 {
  while(front<=MAX-1)
  {
   printf("%d\t",deque[front]);
   front++;
  }
  front=0;
  while(front<=rear)
  {
   printf("%d\t",deque[front]);
   front++;
  }
 }
 printf("\n");
}


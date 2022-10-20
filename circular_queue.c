#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *f = NULL;     // f == front
struct node *r = NULL;     // r== rare
void cirqins(int d) 		// and the t is used for temp . 
{
	struct node* n;
	n = (struct node*)malloc(sizeof(struct node));
	n->data = d;
	n->next = NULL;
	if((r==NULL)&&(f==NULL))
	{
		f = r = n;
		r->next = f;
	}
	else
	{
		r->next = n;
		r = n;
		n->next = f;
	}
} 
void cirqdel() 
{
	struct node* t;
	t = f;
	if((f==NULL)&&(r==NULL)){
		printf("\n---------->This queue is Empty<----------");
	}

	printf(" -------> The element %d is deleted from the queue<-------- \n");

	 if(f == r){
		f = r = NULL;
		free(t);
	}
	else{
		f = f->next;
		r->next = f;
		free(t);
	}
	
	
}
void cirqdisplay(){ 
	struct node* t;
	t = f;
	if((f==NULL)&&(r==NULL))
		printf("\nQueue is Empty");
	else{
		do{
			printf("\n%d",t->data);
			t = t->next;
		}while(t != f);
	}
}
int main()
{
	int x,n,i,data;
	printf("Enter Your Choice:-");
	do{
		printf(" 1.Insert an element \n");
		printf(" 2.Delete an element\n ");
		printf(" 3.Display the queue\n ");
		printf(" 4.Exit from thr program\n");
		printf(" Enter your choice\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("\nEnter the number of data");
				scanf("%d",&n);
				printf("\nEnter your data");
				i=0;
				while(i<n){
					scanf("%d",&data);
					cirqins(data);
					i++;
				}
				break;
			case 2:
			cirqdel();
				
				break;
			case 3:
				 cirqdisplay();
				break;
			case 4:
				break;
			default:
				printf("\n ------------ This is a incorrect Choice ------------");
			
		}
	}while(x<=3);
return 0;
}
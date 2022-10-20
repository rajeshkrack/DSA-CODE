#include<stdio.h>
#include<stdlib.h>

struct nodebtree
{
	int info;
	struct nodebtree *front;
	struct nodebtree *rare;
};
struct nodebtree *stack[100];
int top=0;


struct nodebtree *createbst(struct btree *root,int item)
{
 struct nodebtree *newnode,*ptr,*par;
 newnode=(struct nodebtree *)malloc(sizeof(struct nodebtree));
 if(newnode==NULL)
 {
  printf("Unable to allocate memory\n");
  exit(0);
 }
 newnode->info=item;
 newnode->front=NULL;
 newnode->rare=NULL;
 if(root==NULL)
 {
  root=newnode;
 }
 else
 {
  ptr=root;
  par=NULL;
  while(ptr!=NULL)
  {
   par=ptr;
   if(item<=ptr->info)
   {
    ptr=ptr->front;
   }
   else
   {
    ptr=ptr->rare;
   }
  }
  if(item<par->info)
  {
   par->front=newnode;
  }
  else
  {
   par->rare=newnode;
  }
 }
 return root;
}





struct nodebtree *postorder(struct nodebtree *root)
{
	int m;
	stack[top]=NULL;
	struct nodebtree *ptr,*q;
	ptr=q=root;
	while(1)
	{
		while(ptr->front!=NULL)
		{
			top=top+1;
			stack[top]=ptr;
			ptr=ptr->front;
		}
		while(ptr->rare==NULL||ptr->rare==q)
		{
			printf("%d ",ptr->info);
			q=ptr;
			if(stack[top]==NULL)
			{
				return root;
			}
			ptr=stack[top];
			top=top-1;
		}
		top=top+1;
		stack[top]=ptr;
		ptr=ptr->rare;
	}
	return root;
}

struct nodebtree *preorder(struct nodebtree *root)
{
	stack[top]=NULL;
	struct nodebtree *ptr;
	ptr=root;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		if(ptr->rare!=NULL)
		{
			top=top+1;
			stack[top]=ptr->rare;
		}
		if(ptr->front!=NULL)
		{
			ptr=ptr->front;
		}
		else
		{
			ptr=stack[top];
			top=top-1;
		}
	}
	return root;
}
struct nodebtree *inorder(struct nodebtree *root)
{
	struct nodebtree *ptr;
	stack[top]=NULL;
	ptr=root;
	while(ptr!=NULL)
	{
		top=top+1;
		stack[top]=ptr;
		ptr=ptr->front;
	}
	ptr=stack[top];
	top=top-1;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		if(ptr->rare!=NULL)
		{
			ptr=ptr->rare;
			while(ptr!=NULL)
			{
				top=top+1;
				stack[top]=ptr;
				ptr=ptr->front;
			}
		}
		ptr=stack[top];
		top=top-1;
	}
	return root;
}

int main()
{
	struct nodebtree *root=NULL;
	int x,item;
	do
	{
        printf("    !!!! WELCOME TO THE CODE WORLD  BST WITHOUT USING RECURSION   !!!!");
		printf("\n----------------1.Create a BST---------------");
		printf("\n----------------2.Inorder traversal---------------");
		printf("\n----------------3.Pre-order traversal---------------");
		printf("\n----------------4.Post-order traversal---------------");
		printf("\n----------------5.Exit from the program---------------");
		printf("\n----------------Enter your choice---------------");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
			printf("Enter -1 to terminate\n");
			printf("Enter the data item\n");
			scanf("%d",&item);
			while(item!=-1)
			{
				root=createbst(root,item);
				printf("Enter the data item\n");
				scanf("%d",&item);
			}
			printf("Binary tree is created\n");
			break;
			case 2:
			if(root==NULL)
			{
				printf("In-order traversal:Binary tree is empty\n");
			}
			else
			{
				printf("In-order traversal\n");
				root=inorder(root);
				break;	
			}	
			break;
			case 3:
			if(root==NULL)
			{
				printf("Pre-order traversal:Binary tree is empty\n");
			}
			else
			{
				printf("Pre-order traversal\n");
				root=preorder(root);
				break;
			}
			break;
			case 4:
			if(root==NULL)
			{
				printf("Post-order traversal:Binary tree is empty\n");
			}
			else
			{
				printf("Post-order traversal\n");
				root=postorder(root);
				break;
			}
			break;
			
		}
	}
	while(x<=4);
}
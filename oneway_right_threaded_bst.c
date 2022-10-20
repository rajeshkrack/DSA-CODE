#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int info;
	int rthread;
	struct tree *left;
	struct tree *right;
};

void inorderbst(struct tree *root)
{
	struct tree *raj,*par;
	if(root==NULL)
	{
		printf("------- OHOO NOOOO  TREE IS EMPTY -------- \n");
		exit(0);
	}
	raj=root;
	do
	{
		par=NULL;
		while(raj!=NULL)
		{
			par=raj;
			raj=raj->left;
		}
		if(par!=NULL)
		{
			printf("%d ",par->info);
			raj=par->right;
			while(par->rthread==1&&raj!=NULL)
			{
				printf("%d ",raj->info);
				par=raj;
				raj=raj->right;
			}
		}
	}while(raj!=NULL);
}
struct tree *insertelement(struct tree *root,int item)
{
	struct tree *nextnode,*par,*raj;
	nextnode=(struct tree *)malloc(sizeof(struct tree));
	if(nextnode==NULL)
	{
		printf("Unable to allocate memory\n");
		exit(0);
	}
	nextnode->info=item;
	nextnode->left=NULL;
	nextnode->rthread=1;
	struct tree *right=NULL;
	if(root==NULL)
	{
		root=nextnode;
		nextnode->right=NULL;
		nextnode->rthread=0;
	}
	else
	{
		par=NULL;
		raj=root;
		while(raj!=NULL)
		{
			par=raj;
			if(item<raj->info)
			{
				raj=raj->left;
			}
			else
			{
				if(raj->rthread==1)
				{
					raj=NULL;
				}
				else
				{
					raj=raj->right;
				}
			}
		}
		if(item<par->info)
		{
			par->left=nextnode;
			nextnode->right=par;
			nextnode->rthread=1;
			
		}
		else
		{
			if(par->rthread==1)
			{
				par->rthread=0;
				nextnode->rthread=1;
				nextnode->right=par->right;
				par->right=nextnode;
			}
			else
			{
				nextnode->rthread=0;
				nextnode->right=NULL;
				par->right=nextnode;
			}
		}
	}
	return root;
}
struct tree *createbst(struct tree *root)
{
	int n,i,data;
	printf("-----Please enter the number of elements------\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("---Enter the item you want to insert--\n");
		scanf("%d",&data);
		root=insertelement(root,data);
	}
	return root;
}
int main()
{
	int ch;
	struct tree *root=NULL;
	while(1)
	{
		printf("\n1.To create a right threaded binary search tree--");
		printf("\n2. To perform inorder traversal");
		printf("\n3. To Exit from the program\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			root=NULL;
			root=createbst(root);
			break;
			case 2:
			inorderbst(root);
			break;
			case 3:
			return 0;
			break;
			default:
			printf("--------------ERROR (INPUT IS NOT VALLID ) ------------\n");
		}
	}
}
// Right-in threaded Binary Trees

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node *right;
	struct node *left;
	int thread;
};
struct node *root=NULL;
struct node *insert_node(struct node *root,struct node *ptr,struct node *rt)
{
	if(root==NULL)
	{
		root=ptr;
		if(rt!=NULL)
		{
			root->right=rt;
			root->thread=1;
		}
	}
	else if(ptr->val<root->val)
	{
		root->left=insert_node(root->left,ptr,root);
	}
	else
	{
		if(root->thread==1)
		{
			root->right=insert_node(NULL,ptr,rt);
			root->thread=0;
		}
		else
		{
			root->right=insert_node(root->right,ptr,rt);
		}
	}
	return root;
}
struct node *create_threadedtree()
{
	struct node *ptr;
	int num;
	printf("\nEnter the elements,press -1 to terminate:");
	scanf("%d",&num);
	while(num!=-1)
	{
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->val=num;
		ptr->left=ptr->right=NULL;
		ptr->thread=0;
		root=insert_node(root,ptr,NULL);
		printf("\nEnter the next element:");
		fflush(stdin);
		scanf("%d",&num);
	}
	return root;
}
void inorder(struct node *root)
{
	struct node *ptr=root,*prev;
	do
	{
		while(ptr!=NULL)
		{
			prev=ptr;
			ptr=ptr->left;
		}
		if(prev!=NULL)
		{
			printf("%d ",prev->val);
			ptr=prev->right;
			while(prev!=NULL && prev->thread)
			{
				printf("%d ",ptr->val);
				prev=ptr;
				ptr=ptr->right;
			}
		}
	}
	while(ptr!=NULL);
}
int main()
{
	printf("Threaded Binary tree program.");
	struct node *root=NULL;
	create_threadedtree();
	printf("\nThe inorder traversal of the tree can be given as:");
	inorder(root);
}

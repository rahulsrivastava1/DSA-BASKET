// Binary Tree implementation

#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct node *root;
struct node *create()
{
	int val;
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value to push(-1 for no node):");
	scanf("%d",&val);
	if(val==-1)
	{
		return 0;
	}
	ptr->data=val;
	printf("\nEnter left child of %d",val);
	ptr->left=create();
	printf("\nEnter right child of %d",val);
	ptr->right=create();
	return ptr;
}
int main()
{
	printf("Binary Tree Program using Linked List.");
	struct node *root;
	root=NULL;
	root=create();
	return 0;
}

// Tree Traversal
// Inorder :- Left,Root,Right
// Preorder :- Root,Left,Right
// Postorder :- Left,Right,Root

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
void preorder(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);	
	}
}
void inorder(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void postorder(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
int main()
{
	printf("Binary Tree Program using Linked List.");
	struct node *root;
	root=NULL;
	root=create();
	printf("\nPreorder is:");
	preorder(root);
	printf("\nInorder is:");
	inorder(root);
	printf("\nPostorder is:");
	postorder(root);
	return 0;
}

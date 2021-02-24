// Binary Search Tree

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct node *root=NULL;
struct node *createNode(int val)
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=val;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}
struct node *insertElement(struct node *root, int val)
{
	struct node *ptr, *nodeptr, *parentptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	if(root==NULL)
	{
		root=ptr;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		parentptr=NULL;
		nodeptr=root;
		while(nodeptr!=NULL)
 		{
			parentptr=nodeptr;
			if(val<nodeptr->data)
				nodeptr=nodeptr->left;
			else
				nodeptr = nodeptr->right;
 		}
		if(val<parentptr->data)
			parentptr->left = ptr;
		else
			parentptr->right = ptr;
	}
	return root;
}
struct node *findSmallestElement(struct node *root)
{
	if( (root== NULL) || (root->left == NULL))
		return root;
	else
		return findSmallestElement(root->left);
}
struct node *findLargestElement(struct node *root)
{
	if( (root== NULL) || (root->right == NULL))
		return root;
	else
		return findLargestElement(root->right);
}
struct node *deleteElement(struct node *root, int val)
{
	struct node *cur, *parent, *suc, *psuc, *ptr;
	if(root->left==NULL)
	{
		printf("\n The tree is empty ");
		return(root);
	}
	parent =root;
	cur = root->left;
	while(cur!=NULL && val!= cur->data)
	{
		parent = cur;
		cur = (val<cur->data)? cur->left:cur->right;
	}
	if(cur == NULL)
	{
		printf("\n The value to be deleted is not present in the tree");
		return(root);
	}
	if(cur->left == NULL)
		ptr = cur->right;
	else if(cur->right == NULL)
		ptr = cur->left;
	else
	{
		psuc = cur;
		cur = cur->left;
		while(suc->left!=NULL)
 		{
			psuc = suc;
			suc = suc->left;
 		}
	if(cur==psuc)
 	{
		suc->left = cur->right;
 	}
	else
 	{
		suc->left = cur->left;
		psuc->left = suc->right;
		suc->right = cur->right;
 	}
	ptr = suc;
	}
	if(parent->left == cur)
		parent->left=ptr;
	else
		parent->right=ptr;
	free(cur);		
	return root;
}
void inorderTraversal(struct node *node)
{
	if(root==NULL)
	{
		printf("\nTree is empty!");
		return;
	}
	else
	{
		if(node->left!=NULL)
			inorderTraversal(node->left);
		printf("%d ",node->data);
		if(node->right!=NULL)
			inorderTraversal(node->right);
	}
}
void preorderTraversal(struct node *root)
{
	if(root!= NULL)
	{
		printf("%d ",root->data);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}
void postorderTraversal(struct node *root)
{
	if(root != NULL)
	{
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf("%d ",root->data);
	}
}
int totalNodes(struct node *root)
{
	if(root==NULL)
		return 0;
	else
		return(totalNodes(root->left) + totalNodes(root->right) + 1);
}
int totalExternalNodes(struct node *root)
{
	if(root==NULL)
		return 0;
	else if((root->left==NULL) && (root->right==NULL))
		return 1;
	else
		return (totalExternalNodes(root->left)+totalExternalNodes(root->right));
}
int totalInternalNodes(struct node *root)
{
	if( (root==NULL) || ((root->left==NULL) && (root->right==NULL)))
		return 0;
	else
		return (totalInternalNodes(root->left)+totalInternalNodes(root->right) + 1);
}
int Height(struct node *root)
{
	int leftheight, rightheight;
	if(root==NULL)
		return 0;
	else
	{
		leftheight = Height(root->left);
		rightheight = Height(root->right);
		if(leftheight > rightheight)
			return (leftheight + 1);
		else
			return (rightheight + 1);
	}
}
struct node *mirrorImage(struct node *root)
{
	struct node *ptr;
	if(root!=NULL)
	{
		mirrorImage(root->left);
		mirrorImage(root->right);
		ptr=root->left;
		ptr->left = ptr->right;
		root->right = ptr;
	}
}
struct node *deletetree(struct node *root)
{
	if(root!=NULL)
	{
		deleteroot(root->left);
		deleteroot(root->right);
		free(root);
	}
}
int main()
{
	printf("Binary Search Tree program using Linked List");
	while(1)
	{
		int option,val;
		struct node *ptr;
		printf("\nMENU");
		printf("\n1.insert a node 2.preorder Traversal 3.inorder Traversal 4.postorder Traversal 5.small element\n");
		printf("6.large element 7.delete a node 8.total no. of nodes 9.total no. of external nodes 10.total no. of internal nodes\n");
		printf("11.height of tree 12.mirror image of tree 13.delete the tree 14.exit:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\nEnter the value of the new node:");
				scanf("%d", &val);
				root=insertElement(root,val);
				break;
			case 2:
				printf("\nThe elements of the tree are:\n");
				preorderTraversal(root);
				break;
			case 3:
				printf("\nThe elements of the tree are:\n");
				inorderTraversal(root);
				break;
			case 4:
				printf("\nThe elements of the tree are:\n");
				postorderTraversal(root);
				break;
			case 5:
				ptr = findSmallestElement(root);
				printf("\n Smallest element is :%d",ptr->data);
				break;
			case 6:
				ptr = findLargestElement(root);
				printf("\n Largest element is :%d",ptr->data);
				break;
			case 7:
				printf("\nEnter the element to be deleted:");
				scanf("%d",&val);
				root= deleteElement(root, val);	
				break;
			case 8:
				printf("\nTotal no. of nodes=%d",totalNodes(root));
				break;
			case 9:
				printf("\nTotal no. of external nodes=%d",totalExternalNodes(root));		
				break;
			case 10:
				printf("\nTotal no. of internal nodes=%d",totalInternalNodes(root));		
				break;
			case 11:
				printf("\nThe height of the tree=%d",Height(root));
				break;
			case 12:
				root= mirrorImage(root);
				break;
			case 13:
				root= deletetree(root);
				break;
			case 14:
				exit(0);
				break;
			default:
				printf("\nEnter correct choices!");
		}
	}
	return 0;
}

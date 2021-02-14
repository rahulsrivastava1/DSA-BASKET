// Joseuph's problem using circular Linked list

#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct node 
{
	int player_id;
	struct node *next;
};
struct node *start,*ptr,*new_node;
int main()
{
	int n,k,i,j;
	printf("Joseuph's Problem.");
	printf("\nEnter the number of players:");
	scanf("%d",&n);
	printf("\nEnter the value of k:");
	scanf("%d",&k);
	start=(struct node *)malloc(sizeof(struct node));
	start->player_id=1;
	ptr=start;
	for(i=2;i<=n;i++)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		ptr->next=new_node;
		new_node->player_id=i;
		new_node->next=start;
		ptr=new_node;
	}
	for(i=n;i>1;i--)
	{
		for(j=0;j<k-1;j++)
		{
			ptr=ptr->next;
		}
		ptr->next=ptr->next->next;
	}
	printf("\nThe winner player is: %d.",ptr->player_id);
	return 0;
}

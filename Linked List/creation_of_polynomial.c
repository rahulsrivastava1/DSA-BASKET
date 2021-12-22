// Create polynomial using linked list

#include<stdio.h>
#include<stdlib.h>
struct node{
	int number;
	int coeff;
	struct node *next;
};
struct node *head=NULL;
struct node *newnode,*temp,*last;
void createPoly()
{
	int run=1,num,coeff;
	while(run==1)
	{
		printf("Enter the power:\n");
		scanf("%d",&num);
		printf("Enter its Coefficient:\n");
		scanf("%d",&coeff);
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->coeff=coeff;
		newnode->number=num;
		newnode->next=0;
		if(head==NULL)
		{
			head=newnode;
			last=head;
			
	    }
	    else{
	    	last->next=newnode;
	    	last=last->next;
		}
		printf("Press 1 to continue adding nodes\n");
		printf("Press 2 to exit\n");
		scanf("%d",&run);
	}
	temp=head;
	printf("The polynomial is :\n");
	while(temp!=0)
	{
		if(temp->coeff>=0)
		printf("+%dx^%d ",temp->coeff,temp->number);
		else
		printf("%dx^%d ",temp->coeff,temp->number);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	while(1){
		printf("1.Create a polynomial\n");
	printf("2.Exit\n");
	int choice;
	scanf("%d",&choice);
	switch(choice){
		case 1:
			createPoly();
			break;
		case 2:
			exit(0);
	}
	}
	
}

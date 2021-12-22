// Header Linked List

#include<stdio.h>
#include<stdlib.h>
int count=0;
struct node 
{
	int data;
	struct node *next;
};
struct node *head;
struct node *header;
void beginsert()
{
	struct node *ptr;
	int val;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value to push:");
	scanf("%d",&val);
	ptr->data=val;
	ptr->head=header->next;
	head=ptr;
	header->next=head;
	count++;
	header->data=count;
	printf("\nNode inserted!");
}
void lastinsert()
{
	struct node *ptr,*temp;
	int val;
	temp=head;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value to push:");
	scanf("%d",&val);
	ptr->data=val;
	ptr->next=NULL;
	int temp1=header->data;
	while(temp1>1)
	{
		temp=temp->next;
		temp1--;
	}
	temp->next=ptr;
	count++;
	header->data=count;
	printf("\nNode inserted!");
}
void randomInsert()
{
	int loc,val;
	printf("\nEnter the value to push:");
	scanf("%d",&val);
	printf("\nEnter the location after you want to insert the node:");
	scanf("%d",&loc);
	if(loc>header->data)
	{
		printf("\nWe can't found the position!");
	}
	else
	{
		struct node *ptr,*temp=head;
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=val;
		ptr->next=NULL;
		while(loc>1)
		{
			temp=temp->next;
			loc--;
		}
		ptr->next=temp->next;
		temp->next=ptr;
		count++;
		header->data=count;
		printf("\Node inserted!");
	}
}
void display()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	int choice =0;  
    while(1)   
    {  
        printf("\nHeader Linked List Program."); 
        printf("\nChoose one option from the following list ...\n"); 
        printf("\n1.Insert in begining 2.Insert at last 3.Insert at any random location 4.Display 5.exit");
        printf("\nEnter your choice:");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            beginsert();      
            break;  
            case 2:  
            lastinsert();         
            break;  
            case 3:  
            randomInsert();       
            break;  
            case 4:  
            display();       
            break;  
            case 5:  
            exit(0);        
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}

// Doubly Linked List

#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
	struct node *prev;
    int data;  
    struct node *next;   
};  
struct node *head;  
void beginsert()
{
	int val;
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value to push:");
	scanf("%d",&val);
	ptr->data=val;
	if(head==NULL)
	{
		ptr->next=NULL;
		ptr->prev=NULL;
		head=ptr;
		printf("\nNode inserted!");
	}
	else
	{
		ptr->prev=NULL;
		ptr->next=head;
		head->prev=ptr;
		head=ptr;
		printf("\nNode inserted!");
	}
}
void lastinsert()
{
	int val;
	struct node *ptr,*temp;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value to push:");
	scanf("%d",&val);
	ptr->data=val;
	if(head==NULL)
	{
		ptr->next=NULL;
		ptr->prev=NULL;
		head=ptr;
		printf("\nNode inserted!");
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->prev=temp;
		ptr->next=NULL;
		printf("\nNode inserted!");
	}
}
void randominsert()
{
	int val,loc,i;
	struct node *ptr,*temp;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value to push:");
	scanf("%d",&val);
	printf("\nEnter the location after you want to add node:");
	scanf("%d",&loc);
	ptr->data=val;
	temp=head;
	for(i=0;i<loc;i++)
	{
		temp=temp->next;
		if(temp->next==NULL)
			printf("\ncan't insert!");
	}
	ptr->next=temp->next;
	ptr->prev=temp;
	temp->next=ptr;
	tenp->next->prev=ptr;
	printf("\nNode inserted!");
}  
void begin_delete()
{
	struct node *temp;
	if(head==NULL)
		printf("\nUNDERFLOW!");
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\nNde deleted!");
	}
	else
	{
		temp=head;
		head=head->next;
		head->prev=NULL;
		free(temp);
		printf("\nNode deleted!");
	}
}  
void last_delete()
{
	struct node *temp;
	if(head==NULL)
		printf("\nUNDERFLOW!");
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\nNde deleted!");
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->prev->next=NULL;
		free(ptr);
		printf("\nNode deleted!");
	}
}  
void random_delete()
{
	struct node *temp,*ptr;
	temp=head;
	int val;
	printf("\nEnter the value of node which you want to delete:");
	scanf("%d",&val);
	while(temp->data!=val)
	{
		temp=temp->next;
	}
	if(temp->next==NULL)
		printf("\nCan't delete!");
	else if(temp->next->next==NULL)
	{
		temp->next=NULL;
		printf("\nNode deleetd!");
	}
	else
	{
		ptr=temp->next;
		temp->next=ptr->next;
		ptr->next->prev=temp;
		free(ptr);
		printf("\nNode deleted!");
	}
}  
void display()
{
	struct node *temp;
	if(head==NULL)
		printf("\nEmpty Linked List!");
	else
	{
		temp=head;
		printf("\nPrinting values are:");
		while(temp->next!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
int main ()  
{  
    int choice =0;  
    while(1)   
    {  
        printf("Doubly Linked List Program."); 
        printf("\nChoose one option from the following list ...\n"); 
        printf("\n1.Insert in begining 2.Insert at last 3.Insert at any random location 4.Delete from Beginning\n");
        printf("5.Delete from last 6.Delete node after specified location 7.Show 8.Exit");  
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
            randominsert();       
            break;  
            case 4:  
            begin_delete();       
            break;  
            case 5:  
            last_delete();        
            break;  
            case 6:  
            random_delete();          
            break;  
			case 7: 
            display();        
            break;  
            case 8:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}

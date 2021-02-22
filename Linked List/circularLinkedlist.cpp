// Circular Linked List

#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  
void beginsert()
{
	struct node *temp,*ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value to push:");
	scanf("%d",&ptr->data);
	if(head==NULL)
	{
		head=ptr;
		ptr->next=head;
		printf("\nNode inserted!");
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->next=head;
		head=ptr;
		printf("\nNode inserted!");
	}
	
}   
void lastinsert()
{
	struct node *temp,*ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value to push:");
	scanf("%d",&ptr->data);
	if(head==NULL)
	{
		head=ptr;
		ptr->next=head;
		printf("\nNode inserted!");
	}
	else
	{
		temp->next=ptr;
		ptr->next=head;
		printf("\nNode inserted!");
	}
}    
void begin_delete()
{
	struct node *temp;
	if(head==NULL)
		printf("\nUNDERFLOW!");
	else
	{
		if(head->next==head)
		{
			head=NULL;
			free(head);
			printf("\nNode deleted!");
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=head->next;
			free(head);
			head=temp->next;
			printf("\nNode deleted!");	
		}
	}
}  
void last_delete()
{
	struct node *temp,*ptr;
	if(head==NULL)
		printf("\nUNDERFLOW!");
	else
	{
		if(head->next==head)
		{
			head=NULL;
			free(head);
			printf("\nNode deleted!");
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				ptr=temp;
				temp=temp->next;
			}
			ptr->next=temp->next;
			free(ptr);
			printf("\nNode deleted!");
		}
	}
}    
void display()
{
	struct node *temp;
	if(head==NULL)
		printf("\nLinked List is empty!");
	else
	{
		temp=head;
		printf("\nPrinting values are:");
		while(temp->next!=head)
		{
			printf("%d ",temp->data);  
            temp=temp-> next;
		}
		printf("%d ",temp->data);
	}
}  
int main ()  
{  
    int choice =0;  
    while(1)   
    {  
        printf("\nCircular Linked List Program."); 
        printf("\nChoose one option from the following list ...\n"); 
        printf("\n1.Insert in begining 2.Insert at last 3.Delete from Beginning\n");
        printf("4.Delete from last 5.Show 6.Exit");  
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
            begin_delete();       
            break;  
            case 4:  
            last_delete();       
            break;  
            case 5:  
            display();        
            break;  
            case 6:  
            exit(0);          
            break;    
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  

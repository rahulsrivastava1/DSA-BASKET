#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create(struct node*);
struct node *display(struct node*);
struct node *delete_beg(struct node*);
struct node *delete_end(struct node*);
struct node *delete_mid(struct node*);

int main()
{
    int option;
	do
	{
	    printf("\n** Main Menu** \n");
	    printf("1. Create a list\n");
	    printf("2. Display the list\n");
	    printf("3. Delete a node from beginning\n");
	    printf("4. Delete a node from end\n");
	    printf("5. Delete the given node\n");
	    printf("6.exit\n");
	    printf("Enter your option:");
	    scanf("%d",&option);
	    switch(option)
	    {
	    	case 1: start=create(start);
	    	         printf("\n LINKED LIST CREATED");
	    	         break;
	    	case 2: start=display(start);
			         break;
			case 3: start=delete_beg(start);
			         break;
			case 4: start=delete_end(start);
			         break;
			case 5: start=delete_mid(start);
			         break;
		    case 6: exit(1);
					 		 		 		          
		}
		
   	}
	   while(option!=6);
	 
	 return 0;   	
}
struct node *create(struct node *start)
{
        struct node *new_node, *ptr;
        int num;
        printf("\n Enter -1 to end");
        printf("\n Enter the data : ");
        scanf("%d", &num);
        while(num!=-1)
        {
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node -> data=num;
        if(start==NULL)
        {
            new_node -> next = NULL;
            start = new_node;
        }
        else
        {
        ptr=start;
        while(ptr->next!=NULL)
        ptr=ptr->next;
        ptr->next = new_node;
        new_node->next=NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
        }
        return start;
}
struct node *display(struct node *start)
{
        struct node *ptr;
        ptr = start;
        while(ptr != NULL)
        {
        printf("\t %d", ptr -> data);
        ptr = ptr -> next;
        }
        return start;
}
struct node *delete_beg(struct node *start)
{
        struct node *ptr;
        ptr = start;
        start = start -> next;
        free(ptr);
        return start;
}
struct node *delete_end(struct node *start)
{
        struct node *ptr, *preptr;
        ptr = start;
        while(ptr -> next != NULL)
        {  
            preptr = ptr; 
            ptr = ptr -> next;
        }
        preptr -> next = NULL;
        free(ptr);
        return start;
}
struct node *delete_mid(struct node *start)
{
        struct node *ptr, *preptr;
        int val;
        printf("\n Enter the value of the node which has to be deleted : ");
        scanf("%d", &val);
        ptr = start;
        if(ptr -> data == val)
        {
            start = delete_beg(start);
            return start;
        }
        else
        {
        	while(ptr -> data != val)
            {
                preptr = ptr;
                ptr = ptr -> next;
           }
           preptr -> next = ptr -> next;
           free(ptr);
           return start;
        }
}

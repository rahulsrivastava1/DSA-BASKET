// Flatten a multi-level linked list

// Link to problem :- https://media.geeksforgeeks.org/wp-content/cdn-uploads/flattenList.png

#include<stdio.h>
#include<stdlib.h>
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
struct node
{
	int data;
	struct node *next;
	struct node *child;
};
struct node *createList(int *arr,int n)
{
	struct node *head=NULL;
	struct node *p;
	for(int i=0;i<n;++i)
	{
		if(head==NULL)
		{
			head=p=(struct node*)malloc(sizeof(*p));
		}
		else
		{
			p->next=(struct node*)malloc(sizeof(*p));
			p=p->next;
		}
		p->data=arr[i];
		p->next=p->child=NULL;
	}
	return head;
}
void printList(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}
struct node *createList(void)
{
	int arr1[]={10,5,12,7,11};
	int arr2[]={4,20,13};
	int arr3[]={17,6};
	int arr4[]={9,8};
	int arr5[]={19,15};
	int arr6[]={2};
	int arr7[]={16};
	int arr8[]={3};
	struct node *head1=createList(arr1,SIZE(arr1));
	struct node *head2=createList(arr2,SIZE(arr2));
	struct node *head3=createList(arr3,SIZE(arr3));
	struct node *head4=createList(arr4,SIZE(arr4));
	struct node *head5=createList(arr5,SIZE(arr5));
	struct node *head6=createList(arr6,SIZE(arr6));
	struct node *head7=createList(arr7,SIZE(arr7));
	struct node *head8=createList(arr8,SIZE(arr8));
	head1->child=head2;
	head1->next->next->next->child=head3;
	head3->child=head4;
	head4->child=head5;
	head2->next->child=head6;
	head2->next->next->child=head7;
	head7->child=head8;
	return head1;
}
void flattenList(struct node *head)
{
	if(head==NULL)
		return;
	struct node *temp;
	struct node *tail=head;
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	struct node *cur =head;
	while(cur!=tail)
	{
		if(cur->child)
		{
			tail->next=cur->child;
			temp=cur->child;
			while(temp->next)
			{
				temp=temp->next;
			}
			tail=temp;
		}
		cur=cur->next;
	}
}
int main()
{
	struct node *head=NULL;
	head=createList();
	flattenList(head);
	printList(head);
	return 0;
}

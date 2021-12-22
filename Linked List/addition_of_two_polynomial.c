//Polynomial addition using single linked list

#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int coef;
	int power;
	struct node *next;
}*p=NULL,*q,*r,*x=NULL,*y,*z,*a=NULL,*b,*c;

int insert(int f)
{
	int s,ce,pw;
	while(1)
	{
		printf("\n\n Press 0 to stop entering or 1 to enter next elemnent:");
		scanf("%d",&s);
		switch(s)
		{
			case 0:
				return 0;
			case 1:
				printf("\nEnter co-efficient & power :");
				scanf("%d %d",&ce,&pw);
				if(f==1)
				{
					if(p!=NULL && pw>=q->power)
					{
						printf("\n Insertion failed! Power is greater than the previous!");
						continue;
					}
					r=(struct node*)malloc(sizeof(struct node));
					r->coef=ce;
					r->power=pw;
					r->next=NULL;
					if(p==NULL)
					{
						p=r;
						q=r;
					}
					else
					{
						q->next=r;
						q=r;
					}
				}
				else if(f==2)
				{
					if(x!=NULL && pw>=y->power)
					{
						printf("\n Insertion failed!Power is greater then previous!");
						continue;
					}
					z=(struct node*)malloc(sizeof(struct node));
					z->coef=ce;
					z->power=pw;
					z->next=NULL;
					if(x==NULL)
					{
						x=z;
						y=z;
					}
					else
					{
						y->next=z;
						y=z;
					}
				}
				break;
			default:
				printf("\nInvalid choice!\n\n");
				break;
		}
	}
}

void addition()
{
	printf("\n\n1st polynomial : %d %d",p->coef,p->power);
	q=p->next;
	while(q!=NULL)
	{
		printf(" -> %d %d",q->coef,q->power);
		q=q->next;
	}
	printf("\n\n 2nd polynomial : %d %d",x->coef,x->power);
	y=x->next;
	while(y!=NULL)
	{
		printf(" -> %d %d",y->coef,y->power);
		y=y->next;
	}
	while(1)
	{
		c=(struct node*)malloc(sizeof(struct node));
		if(p->power>x->power)
		{
			c->coef=p->coef;
			c->power=p->power;
			c->next=NULL;
			if(a==NULL)
			{
				a=c;
				b=c;
			}
			else
			{
				b->next=c;
				b=c;
			}
			if(p->next==NULL)
			{
				b->next=p;
				break;
			}
			x=x->next;
		}
		else
		{
			c->coef=p->coef+x->coef;
			c->power=p->power;
			c->next=NULL;
			if(a==NULL)
			{
				a=c;
				b=c;
			}
			else
			{
				b->next=c;
				b=c;
			}
			if(p->next==NULL && x->next==NULL)
			break;
			else if(p->next==NULL)
			{
				b->next=x->next;
				break;
			}
			else if(x->next==NULL)
			{
				b->next=p->next;
				break;
			}
			p=p->next;
			x=x->next;
		}
	}
	printf("\n\nResultant polynomial : %d,%d",a->coef,a->power);
	b=a->next;
	while(b!=NULL)
	{
		printf(" -> %d,%d",b->coef,b->power);
		b=b->next;
	}
}

int main()
{
	printf("Polynomial addition suing linked list.");
	printf("\n Enter two spaces separated integers (co-efficient & power) for each element\n");
	printf("\n Always enter higher powers before lower powers\n");
	printf("\n Enter the 1st Polynomial:");
	insert(1);
	printf("\n Enter the 2nd Polynomial:");
	insert(2);
	addition();
}

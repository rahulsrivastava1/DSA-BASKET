// Modified Bubble sort 
// Time complexity :- O(n)

#include<stdio.h>
void swap(int *b,int *c)
{
int x;
x=*b;
*b=*c;
*c=x;
}
int main ()
{
int a[10],i,j,flag;
printf("enter the unsorted elements\n");
for(i=0;i<5;i++)
scanf("%d",&a[i]);
for(i=0;i<5;i++)
{
    flag=0;
for(j=0;j<4-i;j++)
{
    if(a[j]>a[j+1])
    {
        flag=1;
        swap(&a[j],&a[j+1]);
    }
    }
if(flag==0)
    break;
}
printf("sorted elements are\n");
for(i=0;i<5;i++)
printf("%d\n",a[i]);
}

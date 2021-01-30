// Heap Sort
// Time Complexity :- O(nlogn)

#include<stdio.h>
#define MAX 10
void RestoreHeapUp(int *heap,int index)
{
	int val=heap[index];
	while((index>1) && (heap[index/2]<val))
	{
		heap[index]=heap[index/2];
		index /=2;
	}
	heap[index]=val;
}
void RestoreHeapDown(int *heap,int index,int n)
{
	int val=heap[index];
	int j=index*2;
	while(j<=n)
	{
		if((j<n) && (heap[j]<heap[j+1]))
			j++;
		if(heap[j]<heap[j/2])
			break;
		heap[j/2]=heap[j];
		j=j*2;
	}
	heap[j/2]=val;
}
int main()
{
	int heap[MAX],n,i,j;
	printf("Heap Sort program");
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	printf("\nEnter the elements:");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&heap[i]);
		RestoreHeapUp(heap,i);
	}
	j=n;
	for(i=1;i<=j;i++)
	{
		int temp;
		temp=heap[1];
		heap[1]=heap[n];
		heap[n]=temp;
		n=n-1;
		RestoreHeapDown(heap,1,n);
	}
	n=j;
	printf("\nThe sorted elements are:");
	for(i=1;i<=n;i++)
	{
		printf("%4d",heap[i]);
	}
	return 0;
}

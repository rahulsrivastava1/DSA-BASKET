// Quick Sort
// Time Complexity :-
// Best case :- O(nlogn)
// worst case :- O(n^2) 

#include<stdio.h>
int split(int arr[],int lower,int upper)
{
	int pivot,p,q,temp;
	p=lower+1;
	q=upper;
	pivot=arr[lower];
	while(q>=p)
	{
		while(arr[p]<pivot)
			p++;
		while(arr[q]>pivot)
			q--;
		if(q>p)
		{
			temp=arr[p];
			arr[p]=arr[q];
			arr[q]=temp;
		}
	}
	temp=arr[lower];
	arr[lower]=arr[q];
	arr[q]=temp;
	return q;
}

int quickSort(int arr[],int lower,int upper)
{
	int i;
	if(upper>lower)
	{
		i=split(arr,lower,upper);
		quickSort(arr,lower,i-1);
		quickSort(arr,i+1,upper);
	}
}
int main()
{
	int n,i;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements of an array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nSorted array is:");
	quickSort(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}

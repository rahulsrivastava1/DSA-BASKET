// Merge Sort
// Time Complexity :- O(nlogn)

#include<stdio.h>
#define size 100
int merge(int arr[],int beg,int mid,int end)
{
	int i=beg,j=mid+1,index=beg,temp[size],k;
	while(i<=mid && j<=end)
	{
		if(arr[i]<arr[j])
		{
			temp[index]=arr[i];
			i++;
		}
		else
		{
			temp[index]=arr[j];
			j++;
		}
		index++;
	}
	if(i>mid)
	{
		while(j<=end)
		{
			temp[index]=arr[j];
			j++;
			index++;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index]=arr[i];
			i++;
			index++;
		}
	}
	for(k=beg;k<index;k++)
	{
		arr[k]=temp[k];
	}
}

int mergeSort(int arr[],int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		mergeSort(arr,beg,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,beg,mid,end);
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
	mergeSort(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}


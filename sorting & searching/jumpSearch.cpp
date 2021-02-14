// Jump Search
// Time Complexity :- O(sqrt(n))

#include<stdio.h>
#include<math.h>
int jumpSearch(int a[],int low,int high,int s,int n)
{
	int step,i;
	step=sqrt(n);
	for(i=0;i<step;i++)
	{
		if(s<a[step])
			high=step-1;
		else
			low=step+1;
	}
	for(i=low;i<=high;i++)
	{
		if(a[i]==s)
			return i;
	}
	return -1;
}
int main()
{
	printf("Jump Search Program");
	int i,n,s,result;
	printf("\nEnter the size of an array:");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements of an array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the elements to be search:");
	scanf("%d",&s);
	result=jumpSearch(arr,0,n-1,s,n);
	if(result==-1)
		printf("\nElements not found in the array");
	else
		printf("\nElements found at index %d.",result);
	return 0;
}

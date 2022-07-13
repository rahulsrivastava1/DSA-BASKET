// Merge Sort
// Time Complexity :- O(nlogn)

#include <iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int i=low,j=mid+1,k=0,temp[high-low+1];
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=mid)
        temp[k++]=arr[i++];
    while(j<=high)
        temp[k++]=arr[j++];
    int x=sizeof(temp)/sizeof(temp[0]);
    for(int i=0,j=low;i<x;i++,j++)
        arr[j]=temp[i];
}

void mergeSort(int arr[],int low,int high){
    if(low>=high)
	return;
    if(low<high){
        int mid=low+(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main() {
	int arr[]={12,11,13,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
	return 0;
}

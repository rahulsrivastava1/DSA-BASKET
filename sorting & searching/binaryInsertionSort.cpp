// binary insertion sort
// Time Complexity :- O(N^2)

#include <iostream>
using namespace std;

int binarySearch(int arr[],int item,int low,int high){
    while(low<=high){
        int mid=(low+high)/2;
        if(item==arr[mid])
            return mid+1;
        else if(item>arr[mid])
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int selected=arr[i];
        int loc=binarySearch(arr,selected,0,j);
        while(j>=loc){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=selected;
    }
}

int main() {
	int a[]={37,23,0,17,12,72,31,46,100,88,54};
    int n=sizeof(a)/sizeof(a[0]);
    insertionSort(a,n);
    cout<<"Sorted array:\n";
    for(int i=0;i<n;i++)
        cout<<" "<<a[i];
	return 0;
}

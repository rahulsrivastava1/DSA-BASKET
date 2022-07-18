// Quickselect algorithm to find kth largest element in an array

int partitions(vector<int> &arr,int start,int end){
  int pivot=arr[start],low=start+1,high=end;
  while(low<=high){
    if(arr[low]<pivot && arr[high]>pivot)
      swap(arr[low],arr[high]);
    else if(arr[low]>=pivot)
      i++;
    else if(arr[high]<=pivot)
      j--;
  }
  swap(arr[start],arr[high]);
  return high;
}

int kthLargest(vector<int> &arr,int size,int k){
  int l=0,h=size-1;
  while(true){
    int index=partitions(arr,l,h);
    if(index==k-1)
      return arr[index];
    else if(index<k-1)
      l=index+1;
    else
      h=index-1;
  }
  return 0;
}
  

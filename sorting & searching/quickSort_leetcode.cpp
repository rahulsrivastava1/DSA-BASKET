int partitions(vector<int>& arr,int low,int high){
  if(low>=high)
    return -1;
  int pivot=low,i=pivot+1,j=high;
  while(i<=j){
    if(arr[i]<arr[pivot])
      i++;
    else if(arr[j]>=arr[pivot])
      j--;
    else
      swap(arr[i],arr[j]);
  }
  swap(arr[pivot],arr[j]);
  return j;
}

void quickSort(vector<int>& arr,int low,int high){
  if(low>=high)
    return;
  swap(nums[low+rand()%(high-low+1)],nums[low]);
  int pivot=partitions(arr,low,high);
  quickSort(arr,low,pivot);
  quickSort(arr,pivot+1,high);
}

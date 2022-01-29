// Max Sum Subarray of size K

// function
int maximumSubarraySum(int k,int arr[],int n){
  int ans=INT_MIN;
  int sum=0;
  int i=0;
  int j=0;
  while(j<n){
    sum+=arr[j];
    if(j-i+1<k)
      j++;
    else if(j-i+1==k){
      ans=max(ans,sum);
      sum-=arr[i];
      i++;
      j++;
    }
  }
  return ans;
}

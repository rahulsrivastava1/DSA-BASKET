// Subset Sum
// Variations of 0-1 KnapSack
// Top - Down Approach

bool isSubsetSum(int N,int arr[],int sum){
  int dp[N+1][sum+1];
  for(int i=0;i<N+1;i++){
    for(int j=0;j<sum+1;j++){
      if(i==0)
        dp[i][j]=0;
      if(j==0)
        dp[i][j]=1;
    }
  }
  for(int i=1;i<N+1;i++){
    for(int j=1;j<sum+1;j++){
      if(arr[i-1]<=sum)
        dp[i][j]=dp[i-1][j-arr[i-1] || dp[i-1][j];
      else
        dp[i][j]=dp[i-1][j];
    }
  }
  return dp[N][sum];
}

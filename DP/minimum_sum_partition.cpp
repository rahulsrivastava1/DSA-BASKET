// Minimum sum partition

int SubsetSum(int n,int arr[],int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
            }
        }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
        else
            dp[i][j]=dp[i-1][j];
        }
    }
  vector<int> temp;
	  for(int j=0;j<=sum/2;j++){
	        if(dp[n][j]==1)
	            temp.push_back(j);
	    }
	    int mn=INT_MAX;
	    for(int i=0;i<temp.size();i++){
	        mn=min(mn,sum-(2*temp[i]));
	    }
	    return mn;
}
  public:
	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    for(int i=0;i<n;i++)
	        sum+=arr[i];
	    return SubsetSum(n,arr,sum);
	}

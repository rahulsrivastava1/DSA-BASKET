// Matrix Chain Multiplication

// Recursive Approach -> GIVES TLE

// utility function
int solve(int arr[],int i,int j){
  if(i>=j)
    return 0;
  int mini=INT_MAX;
  for(int k=i;k<j;k++){
    int temp=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
    if(temp<mini)
      mini=temp;
  }
  return mini;
}

// main function
int matrixMultiplication(int N, int arr[]){
  return solve(arr,1,N-1);
}

// Recursion + memorization
class Solution{
private:
    int dp[1001][1001];
    int solve(int arr[],int i,int j){
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int temp=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(arr,1,N-1);
    }
};



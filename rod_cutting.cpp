// Rod Cutting
// Same as unbounded knapsack

int unboundedKnapSack(int n, int w, int val[], int wt[])
    {
        int dp[n+1][w+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<w+1;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<w+1;j++){
                if(wt[i-1]<=j)
                    dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][w];
    }
    int cutRod(int price[], int n) {
        int length[n];
        for(int i=0;i<n;i++)
            length[i]=i+1;
        return unboundedKnapSack(n,n,price,length);
    }

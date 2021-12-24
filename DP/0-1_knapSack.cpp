// 0-1 knapSack Problem
// Recursion+Memoization=DP

// Recursive Approach - obviously gives TLE because it is a problem of DP where we need to store the values
int knapSack(int W, int wt[], int val[], int n) 
    { 
        if(W==0 || n==0)
            return 0;
        if(wt[n-1]<=W){
            return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
        }else if(wt[n-1]>W){
            return knapSack(W,wt,val,n-1);
        }
    }

// DP- approach

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1002][1002];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        if(W==0 || n==0)
            return 0;
        if(dp[n][W]!=-1)
            return dp[n][W];
        if(wt[n-1]<=W){
            return dp[n][W]=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
        }else if(wt[n-1]>W){
            return dp[n][W]=knapSack(W,wt,val,n-1);
        }
    }
};

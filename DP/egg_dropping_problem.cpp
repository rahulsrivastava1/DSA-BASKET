// Egg Dropping Problem

// Recursive Approach
int eggDrop(int e, int f) 
    {
        if(f==0 || f==1)
            return f;
        if(e==1)
            return f;
        int mn=INT_MAX;
        for(int k=1;k<f;k++){
            int temp=1+max(eggDrop(e-1,k-1),eggDrop(e,f-k));
            mn=min(mn,temp);
        }
        return mn;
    }

// Memoization
class Solution{
  public:
  int dp[201][201];
  memset(dp,-1,sizeof(dp));
  int eggDrop(int e, int f) 
    {
        if(f==0 || f==1)
            return f;
        if(e==1)
            return f;
        int mn=INT_MAX;
        if(dp[e][f]!=-1)
           return dp[e][f];
        for(int k=1;k<f;k++){
            int temp=1+max(eggDrop(e-1,k-1),eggDrop(e,f-k));
            mn=min(mn,temp);
        }
        return dp[e][f]=mn;
    }
};


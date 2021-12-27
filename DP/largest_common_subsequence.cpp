// Largest common subsequence

// Recursive Approach
int lcs(int x, int y, string s1, string s2){
  if(x==0 || y==0)
    return 0;
  if(s1[x-1]==s2[y-1])
    return 1+lcs(x-1,y-1,s1,s2);
  else
    return max(lcs(x,y-1,s1,s2),lcs(x-1,y,s1,s2));
}

// Memoization or Top Down Approach
class Solution
{
    public:
    int dp[1002][1002];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        if(x==0 || y==0)
            return 0;
        if(dp[x][y]!=-1)
            return dp[x][y];
        if(s1[x-1]==s2[y-1])
            return dp[x][y]=1+lcs(x-1,y-1,s1,s2);
        else
            return dp[x][y]=max(lcs(x,y-1,s1,s2),lcs(x-1,y,s1,s2));
    }
};

// Bottom Up Approach
int lcs(int x, int y, string s1, string s2)
    {
        int dp[x+1][y+1];
        for(int i=0;i<x+1;i++){
            for(int j=0;j<y+1;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
            }
        }
        for(int i=1;i<x+1;i++){
            for(int j=1;j<y+1;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[x][y];
    }

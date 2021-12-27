// Palindromic patitioning

// GFG accepted

class Solution{
private:
int dp[501][501];
bool isPalindrome(string &s,int i,int j){
    if(i==j)
        return true;
    if(i>j)
        return true;
    while(i<j){
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int solve(string &s,int i,int j){
    if(i>=j)
        return 0;
    if(isPalindrome(s,i,j)==true)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int temp=solve(s,i,k)+solve(s,k+1,j)+1;
        ans=min(ans,temp);
    }
    return dp[i][j]=ans;
}
public:
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        return solve(str,0,str.size()-1);
    }
};

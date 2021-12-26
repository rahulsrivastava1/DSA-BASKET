// Minimum number of deletion in a string to make it a palindrome

// utility function
int helperLCS(int x, int y, string s1, string s2)
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
        return x-dp[x][y];
    }

// main function
    int minimumNumberOfDeletions(string S) { 
       string b=string(S.rbegin(),S.rend());
       int x=S.size();
       return helperLCS(x,x,S,b); 
    } 

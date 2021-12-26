// Minimum number of insertions and deletions

int minOperations(string str1, string str2) 
	{
	    int x=str1.size();
	    int y=str2.size();
	    int dp[x+1][y+1];
        for(int i=0;i<x+1;i++){
            for(int j=0;j<y+1;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
            }
        }
        for(int i=1;i<x+1;i++){
            for(int j=1;j<y+1;j++){
                if(str1[i-1]==str2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        int ans1=str1.size()-dp[x][y]; // Deletion
        int ans2=str2.size()-dp[x][y]; // Insertion
        return ans1+ans2;
	} 

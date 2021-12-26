// Print shortest common Supersequence

string shortestCommonSupersequence(string s1, string s2, int x, int y)
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
        string str;
        int i=x,j=y;
        while(i>0 && j>0){
          if(s1[i-1]==s2[j-1]){
            str.push_back(s1[i-1]);
            i--;
            j--;
          }else{
            if(dp[i][j-1]>dp[i-1][j]){
              str.push_back(s2[j-1]);
              j--;
            }
            else{
              str.push_back(s1[i-1]);
              i--;
            }
          }
        }
        while(i>0){
          str.push_back(s1[i-1]);
          i--;
        }
        while(j>0){
          str.push_back(s2[j-1]);
          j--;
        }
        reverse(str.begin(),str.end());
        return str;
    }

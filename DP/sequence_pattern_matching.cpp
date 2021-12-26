// Sequence Pattern Matching
// is string a match with string b?
// string a is always shorter than or equal to string b

bool patternMatching(int x,int y,string a,string b){
  int dp[x+1][y+1];
  for(int i=0;i<x+1;i++){
    for(int j=0;j<y+1;j++){
      if(i==0 || j==0)
        dp[i][j]=0;
    }
  }
  for(int i=1;i<x+1;i++){
    for(int j=1;j<y+1;j++){
      if(a[i-1]==b[j-1])
        dp[i][j]=1+dp[i-1][j-1];
      else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  int temp=a.size();
  if(temp==dp[x][y])
    return true;
  return false;
}

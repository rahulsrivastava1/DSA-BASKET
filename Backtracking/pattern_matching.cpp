// pattern matching
// using Backtracking
// gives TLE
// can be optimised by DP

// utility function
bool solve(int i,int j,int m,int n,string str,string pattern){
    if(i==m && j==n)
        return true;
    if(i==m){
        for(int k=i;k<n;k++){
        if(pattern[k]!='*')
            return false;
        return true;
    }
    if(j==n){
        return false;
    }
    if(pattern[j]=='?')
      return solve(i+1,j+1,m,n,str,pattern);
    if(pattern[j]=='*')
      return solve(i+1,j,m,n,str,pattern) || solve(i,j+1,m,n,str,pattern);
    if(pattern[j]!=str[i])
      return false;
  return solve(i+1,j+1,m,n,str,pattern);
}

// main function
int wildcard(string str,string pattern){
  int m=str.size();
  int n=pattern.size();
  return solve(0,0,m,n,str,pattern);
}

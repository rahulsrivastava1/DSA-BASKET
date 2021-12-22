// word break
// solution can be optimised by DP
// Time Complexity :- O(2^N)

// utility function
bool solve(int i,int j,int n,string A,vector<string> &B){
  if(j==n){
    if(i==n)
       return true;
    return false;
  }
  if(find(B.begin(),B.end(),A.substr(i,j-i+1))==B.end()){
    return solve(i,j+1,n,A,B);
  }else{
    if(solve(i,j+1,n,A,B)){
      return true;
    }
    return solve(j+1,j+1,n,A,B);
  }
  // here never comes , so we return true because function is bool type
  return true;
}

// main function
int wordBreak(string A,vector<string> &B){
  return solve(0,0,A.size(),A,B);
}

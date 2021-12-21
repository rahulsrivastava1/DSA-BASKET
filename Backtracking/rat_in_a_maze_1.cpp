// Rat in a maze problem
// Expected Time Complexity :- O((3N^2))
// Expected Auxiliary Space: O(L * X)
// Where, L = length of the path, X = number of paths.


// only function

// utility function
void solve(int row,int col,string str,vector<vector<int>> &m,vector<string> &ans){
  int n=m.size();
  if(row<0 || row>=n || col<0 || col>=n || m[row][col]==0)
    return;
  if(row==n-1 && col==n-1){
    ans.push_back(str);
    return;
  }
  int row_change={1,0,0,-1};
  int col_change={0,-1,1,0};
  char direction[]={'D','L','R','U'};
  m[row][col]=0;
  for(int i=0;i<4;i++)
    solve(row+row_change[i],col+col_change[i],str+direction[i],m,ans);
  // backtracking
  m[row][col]=1;
}

// main function
vector<string> findPath(vector<vector<int>> &m,int n){
  vector<string> ans;
  solve(0,0,"",m,ans);
  return ans;
}

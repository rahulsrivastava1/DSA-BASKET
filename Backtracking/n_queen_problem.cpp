// N-Queen Problem

// utility-function 2
bool isSafe(int i,int j,vector<vector<int>> &board,int &n){
  // upper row
  int row=i-1;
  int col=j;
  while(row>=0 && row<n && col>=0 && col<n){
    if(board[row][col]!=0)
      return false;
    row--;
  }
  // upper left diaglonal
  row=i-1;
  col=j-1;
  while(row>=0 && row<n && col>=0 && col<n){
    if(board[row][col]!=0)
      return false;
    row--;
    col--;
  }
  // upper right diagonal
  row=i-1;
  col=j+1;
  while(row>=0 && row<n && col>=0 && col<n){
    if(board[row][col]!=0)
      return false;
    row--;
    col++;
  }
  return true;
}

// utility-function 1
void solve(int row,vector<int> &temp,vector<vector<int>> &ans,vector<vector<int>> &board,int &n){
  if(row==n){
    ans.push_back(temp);
    return;
  }
  for(int j=0;j<n;j++){
    if(isSafe(row,j,board,n)){
      temp.push_back(j+1);
      board[row][j]=1;
      solve(row+1,temp,ans,board,n);
      board[row][j]=0;
      temp.pop_back();
    }
  }
}


// main function
vector<vector<int>> nQueen(int n){
  vector<vector<int>> ans;
  vector<vector<int>> board(n,vector<int> (n,0));
  vector<int> temp;
  solve(0,temp,ans,board,temp);
  return ans;
}

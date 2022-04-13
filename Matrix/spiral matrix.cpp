// Spiral Matrix

// Function:-
void spiral(vector<vector<int>>& matrix){
  int left=0,right=matrix[0].size()-1,top=0,bottom=matrix.size()-1;
  while(left<=right && top<=bottom){
    // moving left to right
    for(int i=left;i<=right;i++)
      cout<<matrix[top][i]<<" ";
    top++;
    // moving top to bottom
    for(int i=top;i<=bottom;i++)
      cout<<matrix[i][right]<<" ";
    right--;
    // moving right to left
    if(top<=bottom){
      for(int i=right;i>=left;i--)
        cout<<matrix[bottom][i]<<" ";
      bottom--;
    }
    // moving bottom to top
    if(left<=right){
      for(int i=bottom;i>=top;i--)
        cout<<matrix[i][left];
      left++;
    }
  }
}

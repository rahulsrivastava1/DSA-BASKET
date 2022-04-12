// Reflect of a n*n matrix 

// Function

void reflect(vector<vector<int>>& matrix){
  for(int i=0;i<n;i++){
    for(int j=0;j<n/2;j++){
      swap(matrix[i][j],matrix[i][n-j-1]);
    }
  }
}

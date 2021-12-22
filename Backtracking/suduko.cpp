// Sudoku

bool row_valid(int row,int col,int grid[N][N],int k){
  for(int i=0;i<9;i++){
    if(grid[row][col]==k)
      return false;
  }
  return true;
}

bool col_valid(int row,int col,int grid[N][N],int k){
  for(int i=0;i<9;i++){
    if(grid[row][col]==k)
      return false;
  }
  return true;
}

bool subbox_valid(int row,int col,int grid[N][N],int k){
  int row_start,col_start,row_end,col_end,i,j;
  for(i=0;i<9;i+=3){
    if(row>=i && row<i+3){
      row_start=i;
      row_end=i+3;
    }
    if(col>=i && col<i+3){
      col_start = i;
      col_end = i+3;
    }
  }
   for(i=row_start;i<row_end;i++){
     for(j=col_start;j<col_end;j++){
       if(grid[i][j] == k)
         return false;
       }
   }
  return true;
}

bool isValid(int row,int col,int grid[N][N],int k){
  if(row_valid(row,col,grid,k) && col_valid(row,col,grid,k) && subbox_valid(row,col,grid,k)){
    return true;
  }
  return false;
}

bool suduko(int row,int col,int grid[N][N]){
  if(row==N)
    return true;
  if(grid[row][col]!=0){
    if(col==8){
      return suduko(row+1,0,grid);
    }else{
      return suduko(row,col+1,grid);
    }
  }
  for(int k=1;k<=9;k++){
    if(isValid(row,col,grid,k)){
      grid[row][col]=k;
      if(col==8){
        if(suduko(row+1,0,grid))
          return true;
      }else{
        if(suduko(i,j+1,grid))
          return true;
      }
      grid[row][col]=0;
    }
  }
  return false;
}

bool solveSudoku(int grid[N][N]){
  return suduko(0,0,grid);
}

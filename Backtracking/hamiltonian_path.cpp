// Hamiltonian Path
// using Backtracking
// DFS not possible

// utility function
bool solve(int node,int count,vector<int> adj[],int n,vector<int> &vis){
  if(count==n)
    return true;
  vis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it]){
      if(solve(it,count+1,adj,n,vis))
        return true;
    }
  }
  vis[node]=0;
  return false;
}

// main function
bool check(int N,int M,vector<vector<int>> Edges){
  vector<int> adj[N+1];
  for(auto it:Edges){
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
  }
  vector<int> vis(N+1,0);
  for(int i=1;i<=N;i++){
    if(!vis[i]){
      if(solve(i,1,adj,N,vis))
        return true;
    }
  }
  return false;
}

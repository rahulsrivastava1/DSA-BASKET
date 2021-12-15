// Bipartite Graph 
// using BFS
// Time Complexity :- O(N+E)
// Space Complexity :- O(N+E)+O(N)+O(N)

#include<bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int src,vector<int> adj[],int color[]){
  queue<int> q;
  q.push(src);
  color[src]=1;
  while(!q.empty()){
    int node=q.front();
    q.pop();
    for(auto it:adj[node]){
      if(color[it]==-1){
        color[it]=1-color[node];
        q.push(it);
      }else if(color[it]==color[node]){
        return false;
      }
    }
  }
  return true;
}

bool checkBipartite(vector<int> adj[],int V){
  int color[V];
  memset(-1,color,sizeof color);
  for(int i=0;i<V;i++){
    if(color[i]==-1){
      if(!bipartitieBfs(i,adj,color))
        return false;
    }
  }
  return true;
}

// driver code
int main(){
  int tc;
  cin>>tc;
  while(tc--){
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0;i<E;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    if(checkBipartite(adj,V))
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}

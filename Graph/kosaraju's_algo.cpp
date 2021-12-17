// Kosaraju's Algorithm for Strongly Connected Graph
// Time Complexity :- O(N+E)
// Space Complexity :- O(N+E)+O(N)+O(N)

// Algorithm:-
// 1. sort all the nodes according to finish time using topological sort
// 2. tranpose the graph
// 3. traverse through graph using tranpose and make dfs and print nodes 

#include<bits/stdc++.h>
using namespace std;

void dfs(int node,stack<int>& st,vector<int>& vis,vector<int> adj[]){
  vis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it])
      dfs(it,st,vis,adj);
  }
  st.push(node);
}

void reverse_dfs(int node,vector<int>& vis,vector<int> transpose[]){
  cout<<node<<" ";
  vis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it]
       reverse_dfs(it,vis,transpose);
  }
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
    }
    stack<int> st;
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
      if(!vis[i])
        dfs(i,st,vis,adj);
    }
    
    // transpose of the graph
    vector<int> transpose(V);
    for(int i=0;i<V;i++){
      vis[i]=0;
      for(auto it:adj[i])
        transpose[it].push_back(i);
    }
    while(!st.empty()){
      int node=st.top();
      st.pop();
      if(!vis[node]){
        cout<<"SCC :";
        reverse_dfs(node,vis,transpose);
        cout<<endl;
      }
    }
    
  }
  return 0;
}

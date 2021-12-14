// DFS Traversal
// Undirected Graph

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
  void dfs_helper(int node,vector<int>& vis,vector<int> adj[],vector<int>& dfs_s){
    dfs_s.push_back(node);
    vis[node]=1;
    for(auto it:adj[node]){
      is(!vis[it]
         dfs_helper(it,vis,adj,dfs_s);
    }
  }
public:
  vector<int> dfs(int V,vector<int> adj[]){
    vector<int> dfs_s;
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
      if(!vis[i])
        dfs_helper(i,vis,adj,dfs_s);
    }
    return dfs_s;
  }
};

// driver code
int main(){
  int component;
  cin>>component;
  while(component--){
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0;i<E;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    Solution obj;
    vector<int> ans=obj.dfs(V,adj);
    for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}

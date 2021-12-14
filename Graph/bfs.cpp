// BFS Traversal 
// Undirected Graph

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
  vector<int> bfs(int V,vector<int> adj[]){
    vector<int> bfs;
    vector<int> vis(V,0);
    queue<int> q;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
      int node=q.front();
      q.pop();
      bfs.push_back(node);
      for(auto it:adj[node]){
        if(!vis[it]){
          q.push(it);
          vis[it]=1;
        }
      }
    }
    return bfs;
   }
};


//driver code
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
  vector<int> ans=obj.bfs(V,adj);
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  }
  return 0;
}

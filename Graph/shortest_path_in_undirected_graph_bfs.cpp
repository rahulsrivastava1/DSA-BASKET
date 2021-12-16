// Shortest path in Undirected Graph of unit weight
// using BFS
// Time Complexity :- O(N+E)
// Space Complexity :- O(N)+O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
  vector<int> distance(int src,int V,vector<int> adj[]){
    vector<int> dist(V,INT_MAX);
    queue<int> q;
    dist[src]=0;
    q.push(src);
    while(!q.empty()){
      int node=q.front();
      q.pop();
      for(auto it:adj[node]){
        if(dist[it]+1<dist[it]){
          dist[it]=dist[it]+1;
          q.push(it);
        }
      }
    }
    return dist;
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
      int src;
      cin>>src;
      Solution obj;
      vector<int> ans=obj.distance(src,V,adj);
      for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
      }
      cout<<endl;
    }
  return 0;
}

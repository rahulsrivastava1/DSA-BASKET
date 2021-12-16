// Shortest Path in DAG weighted 
// Time Complexity :- O(N+E)*2
// Space Complexity :- O(2N)
// Auxilary Space Complexity :- O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
void findTopoSort(int node,vector<pair<int,int>> adj[],int vis[],stack<int>& st){
  vis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it.first]){
      findTopoSort(it,adj,vis,st);
    }
  }
  st.push(node);
}
public:
  vector<int> distance(int src,int V,vector<int> adj[]){
    int vis[V]={0};
    stack<int> st;
    for(int i=0;i<V;i++){
      if(!vis[i]){
        findTopoSort(i,adj,vis,st);
      }
    }
    vector<int> dis(V,INT_MAX);
    dist[src]=0;
    while(!st.empty()){
      int node=st.top();
      st.pop();
      if(dist[node]!=INT_MAX){
        for(auto it:adj[node]){
          if(dis[node]+it.second<dist[it.first])
            dist[it.first]=dist[node]+it.second;
        }
      }
    }
    return dis;
  }
};

// driver code
int main(){
  int component;
  cin>>component;
  while(component--){
    int V,E;
    cin>>V>>E;
    vector<pair<int,int>> adj[V];
    for(int i=0;i<E;i++){
      int u,v,wt;
      cin>>u>>v>>wt;
      adj[u].push_back({v,wt});
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

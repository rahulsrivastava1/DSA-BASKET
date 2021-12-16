// Dijkstra's Algorithm in Undirected Weighted Graph
// Time Complexity :- O((N+E)logN)
// Space Complexity :- O(N)+O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
  vector<int> dijkstras(int src,int V,vector<int> adj[]){
    // min-heap
    // dist,src
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(V,INT_MAX);
    dist[src]=0;
    pq.push_back({0,src});
    while(!pq.empty()){
      int dist=pq.top().first;
      int prev=pq.top().second;
      pq.pop();
      for(auto it:adj[prev]){
        int next=it.first;
        int nextDist=it.second;
        if(dist+nextDist<dist[next]){
          dist[next]=dist+nextDist;
          pq.push_back({dist[next],next});
        }
      }
    }
    return dist;
  }
};

// driver code
int main(){
  int tc;
  cin>>tc;
  while(tc--){
    int V,E;
    cin>>V>>E;
    vector<pair<int,int>> adj[V];
    for(int i=0;i<E;i++){
      int u,v,wt;
      cin>>u>>v>>wt;
      adj[u].push_back({v,wt});
      adj[v].push_back({u,wt});
    }
    int src;
    cin>>src;
    Solution obj;
    vector<int> ans=obj.dijkstras(src,V,adj);
    for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}

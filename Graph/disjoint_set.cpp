// Disjoint Set Data Structure
// Time Complexity :- O(4alpha) = O(4)
// Space Complexity :- O(2N)

// only function

int parent[100000];
int rank[100000];

void makeSet(){
  for(int i=1;i<=n;i++){
    parent[i]=i;
    rank[i]=0;
  }
}

int findPar(int node){
  if(node==parent[node])
    return node;
  return parent[node]=findPar(parent[node]);
}

void union(int x,int y){
  int u=findPar(x);
  int v=findPar(y);
  if(rank[u]<rank[v]){
    parent[u]=v;
  }else if(rank[v]<rank[u]){
    parent[v]=u;
  }else{
    parent[v]=u;
    rank[u]++;
  }
}

void main(){
  makeSet();
  int m;
  cin>>m;
  while(m--){
    int u,v;
    union(u,v);
  }
  // if 2 and 3 belong to same component or not
  if(findPar(2)!=findPar(3)){
    cout<<"Different component"<<endl;
  }else{
    cout<<"Same Component"<<endl;
  }
}

// permutations with case change

#include<iostream>
using namespace std;

void solve(string a,string op){
  if(a.size()==0){
    cout<<op<<" ";
    return;
  }
  string op1=op;
  string op2=op;
  op1.push_back(a[0]);
  op2.push_back(toupper(a[0]));
  a.erase(a.begin()+0);
  solve(a,op1);
  solve(a,op2);
}

// driver code
int main(){
  string a="abc";
  string op="";
  solve(a,op);
  return 0;
}

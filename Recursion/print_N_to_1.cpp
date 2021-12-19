// printing N to 1

#include<iostream>
using namespace std;

void printReverse(int n){
  if(n==1){
    cout<<n<<" ";
    return;
  }
  cout<<n<<" ";
 printReverse(n-1); 
}

int main(){
  int n;
  cin>>n;
  printReverse(n);
  return 0;
}

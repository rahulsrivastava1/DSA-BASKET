// printing N to 1

#include<iostream>
using namespace std;

void printReverse(int n){
  cout<<n<<" ";
  if(n==1)
    return;
 printReverse(n-1); 
}

int main(){
  int n;
  cin>>n;
  printReverse(n);
  return 0;
}

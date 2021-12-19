// Delete middle element of a stack

class Solution{
  private:
  void solve(stack<int>& s,int k){
    if(k==1){
      s.pop();
      return;
    }
    int temp=s.top();
    s.pop();
    solve(s,k-1);
    s.push(temp);
  }
  public:
  void deleteMiddle(stack<int>& s,int size){
    if(size==0)
      return;
    int k=(size/2)+1;
    solve(s,k);
  }

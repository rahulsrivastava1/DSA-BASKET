// Binary to Decimal

int binary_to_decimal(string s){
  int n=s.size();
  int ans=0;
  for(int i=0;i<n;i++){
    int temp=s[i]-'0';
    ans=ans*2+temp;
  }
  return ans;
}

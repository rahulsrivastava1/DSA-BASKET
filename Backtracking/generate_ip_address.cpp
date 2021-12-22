// Generate IP address

// utility-function 1
bool isValid(string s,int i,int j,int k,int n){
  if(valid_sub(s,0,i) && valid_sub(s,i+1,j) && valid_sub(s,j+1,k) && valid_sub(s,k+1,n-1))
    return true;
  return false;
}

// utility-function 2
bool valid_sub(string s,int i,int j){
  int len=j-i+1;
  if(len>3)
    return false;
  if(s[i]=='0'){
    if(len==1)
      return true;
    return false;
  }
  int num=stoi(s.substr(i,len));
  if(num>=0 && num<=255)
    return true;
  return false;
}

// utility-function 3
void add_string(string s,int i,int j,int k,int n,vector<string>& ans){
  string temp;
  temp.append(s.substr(0,i+1));
  temp.push_back('.');
  temp.append(s.substr(i+1,j-i));
  temp.push_back('.');
  temp.append(s.substr(j+1,k-j));
  temp.push_back('.');
  temp.append(s.substr(k+1,n-k-1));
  ans.push_back(temp);
}

// main function
vector<string> genIp(string &s){
  vector<string> ans;
  int i,j,k,n;
  n=s.size();
  for(i=0;i<n-3;i++){
    for(j=i+1;j<n-2;j++){
      for(k=j+1;k<n-1;k++){
        if(isValid(s,i,j,k,n))
          add_string(s,i,j,k,n,ans);
      }
    }
  }
  return ans;
}

// Print Subsets

// function
void subset(string ip,string op){
  if(ip.size()==0){
    cout<<op<<" ";
    return;
  }
  string op1=op;
  string op2=op;
  op2.push_back(ip[0]);
  ip.erase(ip.begin()+0);
  subset(ip,op);
  subset(ip,op);
}

// leetcode
void subset(int index,vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp){
  if(index==nums.size()){
    ans.push_back(temp);
    temp.pop_back();
    return;
  }
  temp.push_back(nums[index];
  subset(index+1,nums,ans,temp);
  subset(index+1,nums,ans,temp);
}
                 
vector<vector<int>> solve(vector<int>& nums){
  vector<vector<int>> ans;
  vector<int> temp;
  subset(0,nums,ans,temp);
  return ans;
}

// combination sum 2

void solve(int ind,int target,vector<vector<int>> &ans,vector<int>& temp,vector<int>& candidates){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target)
                break;
            temp.push_back(candidates[i]);
            solve(i+1,target-candidates[i],ans,temp,candidates);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,target,ans,temp,candidates);
        return ans;
    }

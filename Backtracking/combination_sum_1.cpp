// combination sum 1

void solve(int i,int sum,int target,int n,vector<int> &temp,vector<vector<int>> &ans,vector<int> &A){
        if(sum==target){
            ans.push_back(temp);
            return;
        }        
        if(i==n || sum>target)
            return;
        sum+=A[i];
        temp.push_back(A[i]);
        solve(i,sum,target,n,temp,ans,A);
        sum-=A[i];
        temp.pop_back();
        solve(i+1,sum,target,n,temp,ans,A);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(),A.end()),A.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,0,B,A.size(),temp,ans,A);
        return ans;
    }

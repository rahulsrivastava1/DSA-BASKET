// Unique Subsets

vector<vector<int>> res;
    map<vector<int>,int> mp;
    void subset(vector<int>& temp,int ind,int n,vector<int>& arr){
        if(ind==n){
            if(mp.find(temp)==mp.end()){
                mp[temp]++;
            }
            return;
        }
        temp.push_back(arr[ind]);
        subset(temp,ind+1,n,arr);
        temp.pop_back();
        subset(temp,ind+1,n,arr);
    }
    
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        res.clear();
        mp.clear();
        sort(arr.begin(),arr.end());
        vector<int> temp;
        subset(temp,0,n,arr);
        for(auto i:mp){
            res.push_back(i.first);
        }
        return res;
    }

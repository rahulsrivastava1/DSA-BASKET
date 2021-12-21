// Joseuphs Problem

void solve(vector<int>& arr,int index,int k,int& ans){
    if(arr.size()==1){
        ans=arr[0];
        return ;
    }
    index=(index+k)%arr.size();
    arr.erase(arr.begin()+index);
    solve(arr,index,k,ans);
}
    int safePos(int n, int k) {
        vector<int> arr;
        int ans=-1;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        k--;
        solve(arr,0,k,ans);
        return ans;
    }

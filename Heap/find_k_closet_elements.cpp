// K closet Elements

// function
 vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<arr.size();i++){
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k)
                pq.pop();
        }
        priority_queue<int> pqq;
        while(!pq.empty()){
            pqq.push(pq.top().second);
            pq.pop();
        }
        while(!pqq.empty()){
            ans.push_back(pqq.top());
            pqq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

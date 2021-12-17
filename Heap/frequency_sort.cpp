// Frequency Sort


// function
vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        priority_queue<pair<int,int>> pq;
        for(auto it:mp){
            pq.push({-it.second,it.first});
        }
        vector<int> ans;
        while(!pq.empty()){
            int freq=pq.top().first;
            int ele=pq.top().second;
            for(int i=0;i<abs(freq);i++)
                ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }

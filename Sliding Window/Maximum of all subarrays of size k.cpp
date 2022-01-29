//Maximum of all subarrays of size k

// function
vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int> ret;
       deque<int> dq;
       for(int i=0;i<n;i++){
           while(!dq.empty() and arr[i]>=arr[dq.back()]) dq.pop_back();
           dq.push_back(i);
           if(i>=k-1){
               if(i-k==dq.front()) dq.pop_front();
               ret.push_back(arr[dq.front()]);
           }
       }
       return ret;
    }

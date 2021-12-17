// K-largest element
// Time Complexity :- O(NlogK)

// function

vector<int> kLargest(int arr[], int n, int k) {
	    vector<int> ans;
	    priority_queue<int> minH;
	    for(int i=0;i<n;i++){
	        minH.push(arr[i]);
	    }
	    int count=0;
	    while(count<k){
	        ans.push_back(minH.top());
	        minH.pop();
	        count++;
	    }
	    return ans;
	}

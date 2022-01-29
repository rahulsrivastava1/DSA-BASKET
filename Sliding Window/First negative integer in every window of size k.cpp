// First negative integer in every window of size k

// function
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    vector<long long> ans;
    queue<int> temp;
    int i=0;
    int j=0;
    while(j<N){
        if(A[j]<0)
            temp.push(A[j]);
        if(j-i+1<K)
            j++;
        else if(j-i+1==K){
            if(temp.empty())
                ans.push_back(0);
            else
                ans.push_back(temp.front());
            if(A[i]==temp.front())
                temp.pop();
            i++;
            j++;
        }
    }
    return ans;
 }


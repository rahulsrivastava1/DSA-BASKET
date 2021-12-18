// Sum of elements between k1'th and k2'th smallest elements 
// using Heap

// function
long long kthsmallest(long long A[],long long N,long long k){
        priority_queue<long long> pq;
        for(long long i=0;i<N;i++){
            pq.push(A[i]);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        long long first=kthsmallest(A,N,K1);
        long long second=kthsmallest(A,N,K2);
        long long sum=0;
        for(long long i=0;i<N;i++){
            if(A[i]>first && A[i]<second)
                sum+=A[i];
        }
        return sum;
    }

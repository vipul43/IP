## Day04
--------
Problem name: First negative integer in every window of size k <br>
Problem link: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#

## Question
-----------

## Idea
-------

## Solution Approach 01
-----------------------
```
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    set<long long> st;
    vector<long long> ans;
    for(long long i=0; i<K; ++i){
        if(A[i]<0){
            st.insert(i);
        }
    }
    st.size()==0 ? ans.push_back(0) : ans.push_back(A[*st.begin()]);
    for(long long i=1; i<N-K+1; ++i){
        long long low = i-1;
        long long high = i+K-1;
        if(st.count(low)==1) st.erase(low);
        if(A[high]<0) st.insert(high);
        st.size()==0 ? ans.push_back(0) : ans.push_back(A[*st.begin()]);
    }
    return ans;
}
```

## Notes
--------

## Solution Approach 02
-----------------------
```
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<long long> dq;
    vector<long long> ans;
    for(long long i=0; i<K; ++i){
        if(A[i]<0) dq.push_back(i);
    }
    dq.size()==0 ? ans.push_back(0) : ans.push_back(A[dq.front()]);
    for(long long i=1; i<N-K+1; ++i){
        long long low = i-1;
        long long high = i+K-1;
        while(!dq.empty() && dq.front()<=low){
            dq.pop_front();
        }
        if(A[high]<0) dq.push_back(high);
        dq.size()==0 ? ans.push_back(0) : ans.push_back(A[dq.front()]);
    }
    return ans;
}
```

## Notes
--------
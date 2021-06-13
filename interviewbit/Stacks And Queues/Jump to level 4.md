## Kth Smallest Element in the Array
------------------------------------
Problem Name: Kth Smallest Element in the Array <br>
Problem Link: https://www.interviewbit.com/problems/kth-smallest-element-in-the-array/

## Question
-----------

## Idea
-------

## Solution Approach 01
-----------------------
```
int Solution::kthsmallest(const vector<int> &A, int B) {
    priority_queue<int> pq;
    for(int i=0; i<A.size(); ++i){
        pq.push(A[i]);
        if(pq.size()>B) pq.pop();
    }
    return pq.top();
}
```

## Notes
--------
- Time complexity is O(nlog(n)). Since each push or pop operation of priority queue takes O(log(n)) time. Space complexity is O(k). Since at any point of time only k elements are stored in the priority queue.
- An equivalent time complexity approach to the above approach is copying the array and sorting it. After than indexing k-1th element. This approach has time complexity O(nlog(n)) and space complexity O(n).

## Solution Approach 02
-----------------------
```
int Solution::kthsmallest(const vector<int> &A, int B) {
    priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.end());
    while(--B){
        pq.pop();
    }
    return pq.top();
}
```

## Notes
--------
- Time Complexity is O(klog(n)). Since each push or pop operation of priority queue takes O(log(n)) time. Space complexity is O(n). Since all elements are stored.

## Kth Smallest Element in the Array
------------------------------------
Problem Name: NUMRANGE <br>
Problem Link: https://www.interviewbit.com/problems/numrange/

## Question
-----------

## Idea
-------

## Solution Approach 01
-----------------------
```
int Solution::numRange(vector<int> &A, int B, int C) {
    int ans= 0;
    int n = A.size();
    for(int i=0; i<n; ++i){
        int limit = i;
        int sum = 0;
        while(limit<n && sum+A[limit]<=C){
            if(sum+A[limit]>=B) {
                ans++;
            }
            sum+=A[limit];
            limit++;
        }
    }
    return ans;
}
```

## Notes
--------

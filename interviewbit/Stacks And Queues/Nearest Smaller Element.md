## Nearest Smaller Element
------------------------
Problem Name: Nearest Smaller Element <br>
Problem Link: https://www.interviewbit.com/problems/nearest-smaller-element/

## Question
-----------

## Idea
-------

## Solution Approach 01
-----------------------
```
vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> stk;
    int n = A.size();
    vector<int> ans;
    ans.push_back(-1);
    stk.push(A[0]);
    for(int i=1; i<n; ++i){
        while(!stk.empty() && stk.top()>=A[i]){
            stk.pop();
        }
        if(stk.empty()){
            ans.push_back(-1);
        } else {
            ans.push_back(stk.top());
        }
        stk.push(A[i]);
    }
    return ans;
}
```

## Notes
--------
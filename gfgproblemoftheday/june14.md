## June 17
----------
Problem Name: Stock span problem <br>
Problem Link: https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

## Question
-----------

## Idea
-------

## Solution Approach 01
-----------------------
```
vector <int> calculateSpan(int price[], int n)
{
    // Your code here
    stack<int> stk;
    vector<int> ans(n, 1);
    for(int i=0; i<n; ++i){
        while(!stk.empty() && price[stk.top()]<=price[i]){
            int temp = stk.top(); stk.pop();
            ans[i]+=ans[temp];
        }
        stk.push(i);
    }
    return ans;
}
```

## Notes
--------

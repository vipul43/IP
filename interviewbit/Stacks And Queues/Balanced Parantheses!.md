## Balanced Paranthesis!
------------------------
Problem Name: Balanced Parantheses! <br>
Problem Link: https://www.interviewbit.com/problems/balanced-parantheses/

## Question
-----------

## Idea
-------

## Solution Approach 01
-----------------------
```
int Solution::solve(string A) {
    stack<char> stk;
    for(int i=0; i<A.size(); ++i){
        if(A[i]=='('){
            stk.push(A[i]);
        } else {
            if(!stk.empty()) stk.pop();
            else return 0;
        }
    }
    return stk.empty();
}
```

## Notes
--------
## Evaluate Expression
------------------------
Problem Name: Evaluate Expression <br>
Problem Link: https://www.interviewbit.com/problems/evaluate-expression/

## Question
-----------

## Idea
-------

## Solution Approach 01
-----------------------
```
int Solution::evalRPN(vector<string> &A) {
    stack<int> stk;
    for(auto str:A){
        if(str=="+"){
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b+a);
        } else if(str=="-"){
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b-a);
        } else if(str=="*"){
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b*a);
        } else if(str=="/"){
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b/a);
        } else {
            stk.push(stoi(str));
        }
    }
    return stk.top();
}

```

## Notes
--------
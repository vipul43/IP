## Min Stack
------------------------
Problem Name: Min Stack <br>
Problem Link: https://www.interviewbit.com/problems/min-stack/

## Question
-----------

## Idea
-------

## Solution Approach 01
-----------------------
```
stack<pair<int, int>> stk;
MinStack::MinStack() {
    while(!stk.empty()){
        stk.pop();
    }
}

void MinStack::push(int x) {
    if(stk.empty()) stk.push({x, x});
    else stk.push({x, min(x, stk.top().second)});
}

void MinStack::pop() {
    if(!stk.empty()) stk.pop();
}

int MinStack::top() {
    if(!stk.empty()) return stk.top().first;
    else return -1;
}

int MinStack::getMin() {
    if(!stk.empty()) return stk.top().second;
    else return -1;
}
```

## Notes
--------
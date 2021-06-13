## June 13
---------
Problem Name: Infix to Postfix  <br>
Problem Link: https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1#

## Question
-----------

## Idea
-------

## Solution Approach 01
-----------------------
```
int prec(char sym){
    if(sym=='+' || sym=='-'){
        return 1;
    }
    if(sym=='*' || sym=='/'){
        return 2;
    }
    if(sym=='^'){
        return 3;
    }
}
//Function to convert an infix expression to a postfix expression.
string infixToPostfix(string s)
{
    // Your code here
    int n = s.size();
    stack<char> stk;
    string ans;
    int i=0;
    for(int i=0; i<n; ++i){
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^' || s[i]=='(' || s[i]==')'){
            if(s[i]=='('){
                stk.push(s[i]);
            } else if(s[i]==')'){
                while(stk.top()!='('){
                    ans+=stk.top();
                    stk.pop();
                }
                stk.pop();
            } else {
                while(!stk.empty() && stk.top()!='(' && prec(stk.top())>=prec(s[i])){
                    ans+=stk.top();
                    stk.pop();
                }
                stk.push(s[i]);
            }
        } else {
            ans+=s[i];
        }
    }
    while(!stk.empty()){
        ans+=stk.top();
        stk.pop();
    }
    return ans;
}
```

## Notes
--------
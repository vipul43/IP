## Simplify Directory Path
------------------------
Problem Name: Simplify Directory Path <br>
Problem Link: https://www.interviewbit.com/problems/simplify-directory-path/

## Question
-----------

## Idea
-------

## Solution Approach 01
-----------------------
```
string Solution::simplifyPath(string A) {
    string token;
    deque<string> dq;
    for(int i=1; i<A.size(); ++i){
        if(A[i]=='/'){
            if(token==".."){
                if(!dq.empty()) dq.pop_back();
            } else if(token!="" && token!="."){
                dq.push_back(token);
            }
            token = "";
        } else {
            token.push_back(A[i]);
        }
    }
    if(token.size()!=0){
        if(token==".."){
            if(!dq.empty()) dq.pop_back();
        } else if(token!="" && token!="."){
            dq.push_back(token);
        }
        token = "";
    }
    while(!dq.empty()){
        token.push_back('/');
        token+=dq.front();
        dq.pop_front();
    }
    if(token=="") token="/";
    return token;
}
```

## Notes
--------
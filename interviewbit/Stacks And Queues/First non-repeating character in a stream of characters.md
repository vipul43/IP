## First non-repeating character in a stream of characters
------------------------
Problem Name: First non-repeating character in a stream of characters <br>
Problem Link: https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

## Question
-----------

## Idea
-------

## Solution Approach 01
-----------------------
```
string Solution::solve(string A) {
    deque<char> dq;
    string ans = "";
    unordered_map<int, int> freq;
    for(int i=0; i<A.size(); ++i){
        if(freq[A[i]-97]==0){
            freq[A[i]-97]++;
            dq.push_back(A[i]);
        } else {
            freq[A[i]-97]++;
            while(!dq.empty() && freq[dq.front()-97]>1){
                dq.pop_front();
            }
        }
        if(dq.empty()) ans+='#';
        else ans+=dq.front();
    }
    return ans;
}
```

## Notes
--------
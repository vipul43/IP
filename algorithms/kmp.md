## Knuth Morris Pratt
---------------------
Algorithm Name: Knuth Morris Pratt Algorithm <br>
TDS Read: https://towardsdatascience.com/pattern-search-with-the-knuth-morris-pratt-kmp-algorithm-8562407dba5b <br>
BBM Read: https://binary-baba.medium.com/string-matching-kmp-algorithm-27c182efa387 <br>
Hackerearth Tutorial: https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/tutorial/ <br>
GeeksForGeeks Read: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/ <br>

## Understanding
----------------

## Longest Prefix Suffix
------------------------
Problem Name: Longest Prefix Suffix <br>
Problem Link: https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1

## Question
-----------


## Idea
-------

## Solution Approach 01
-----------------------
```
int lps(string s)
{
    // Your code goes here
    int n = s.size();
    int top = 0;
    int bottom = 0;
    vector<int> lps(n, 0);
    while(bottom<n){
        bottom++;
        if(s[top]==s[bottom]){
            //if top and bottom pointers are equal then assign top+1 to lps and move both pointers
            lps[bottom] = top+1;
            top++;
        } else {
            //if top and bottom pointers are not equal then roll back top pointer to next potential match
            //which is given by lps[top-1], if there is no potential match go till start
            //in this roll back procedure if anytime encountered matching position, update lps and stop roll back
            while(top!=0 && s[top]!=s[bottom]){
                top = lps[top-1];
            }
            if(s[top]==s[bottom]){
                lps[bottom] = top+1;
                top++;
            }
        }
    }
    return lps[n-1];
}
```

## Notes
--------


##

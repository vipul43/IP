## June 09
---------
Problem Name: Triplet Sum in Array <br>
Problem Link: https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

## Question
-----------

## Idea
-------

## Solution Approach 01
-----------------------
```
bool find3Numbers(int A[], int n, int X)
{
    //Your Code Here
    unordered_set<int> st;
    for(int i=0; i<n; ++i){
        st.insert(A[i]);
    }
    for(auto itr1=st.begin(); itr1!=st.end(); ++itr1){
        for(auto itr2=st.begin(); itr2!=st.end(); ++itr2){
            if(itr1!=itr2){
                int third = X-(*itr1)-(*itr2);
                if(st.count(third)==1 && st.find(third)!=itr1 && st.find(third)!=itr2){
                    return true;
                }
            }
        }
    }
    return false;
}
```

## Notes
--------
- Time complexity is O(n\*n). Since, finding in unordered set takes O(1) time and there are two outer for loops iterating over n. Space complexity is O(n). Since, all the elements of array are stored in the `unordered_set`.

## Solution Approach 02
-----------------------
```
bool find3Numbers(int A[], int n, int X)
{
    //Your Code Here
    sort(A, A+n);
    for(int i=0; i<n-2; ++i){
        int low = i+1;
        int high = n-1;
        while(low<high){
            if(A[i]+A[low]+A[high]<X){
                low++;
            } else if(A[i]+A[low]+A[high]>X){
                high--;
            } else {
                return true;
            }
        }
    }
    return false;
}
```

## Notes
--------
- Time complexity is O(n\*n). Although sorting takes O(nlog(n)), the dominant is two-pointer approach part which has time complexity O(n\*n). Space complexity is O(1), no additional data structure is used for storing.
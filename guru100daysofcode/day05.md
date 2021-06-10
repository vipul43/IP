## Day05
--------
Problem name: Game with String <br>
Problem link: https://practice.geeksforgeeks.org/problems/game-with-string4100/1#

## Question
-----------


## Idea
-------


## Solution Approach 01
-----------------------
```
int minValue(string s, int k){
    // code here
    
    vector<int> arr(26, 0);
    for(auto &ch:s){
        arr[ch-97]++;
    }
    priority_queue<int> pq(arr.begin(), arr.end());
    for(int i=0; i<k; ++i){
        int temp = pq.top(); pq.pop();
        temp--;
        pq.push(temp);
    }
    int ans = 0;
    while(!pq.empty()){
        int temp = pq.top(); pq.pop();
        ans+=temp*temp;
    }
    return ans;
}
```

## Notes
--------

## Solution Approach 02
-----------------------
```
```

## Notes
--------
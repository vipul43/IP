## Day02
--------
Problem name: Generate Binary Numbers <br>
Problem link: https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1#

## Question
-----------
Print Binary representation of all numbers from 1 to N.

## Idea
-------
Iterate through all the numbers from 1 to N and get the binary representation of the number. <br>
The above solution is computationally inefficient. <br>
The optimal approach is to use bfs to generate binary numbers starting from 1 and attesting 0 and 1 to the end of the previous level, at each level of bfs.
```
          1
      /       \
     10       11
   /    \    /  \
  100  101  110 111
  ...
```
In the above way all numbers are generated, and level order traveral gives the numbers in sorted manner.


## Solution Approach 01
-----------------------
```
vector<string> generate(int N)
{
	// Your code here
	vector<string> ans;
	for(int i=1; i<=N; ++i){
	    string s;
	    int num = i;
	    while(num){
    	    s+=to_string(num&1);
	        num>>=1;
	    }
	    reverse(s.begin(), s.end());
	    ans.push_back(s);
	}
	return ans;
}
```

## Notes
--------
- Time complexity is O(N*32), as each number is an integer they can be atmost 32 bit long. Also, equivalent to O(N). Space complexity is O(1).

## Solution Approach 02
-----------------------
```
vector<string> generate(int N)
{
	// Your code here
	vector<string> ans;
	queue<string> q;
	q.push("1");
	while(N--){
	    string temp = q.front(); q.pop();
	    ans.push_back(temp);
	    q.push(temp+"0");
	    q.push(temp+"1");
	}
	return ans;
}
```

## Notes
--------
- Time Complexity is O(V+E) where V are vertices and E are edges. Here Vertices are numbers from 1 through N. As it is binary tree, edges are N-1. So, O(V+E) is also equivalent to O(N). But efficient compared to Solution Approach 01. Space complexity is also O(N).
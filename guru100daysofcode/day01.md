## Day01
--------
Problem name: Maximum of all subarrays of size k <br>
Problem link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#

## Question
-----------
subarray/substring: Contiguous part of array. Consecutive elements of array taken together. <br>
subsequence: Part of the array with same order of elements. The elements of subsequence need not be contiguous part of the original array. <br>
In an array of length n, there will be total of n-k+1 subarrays of size k. <br>
The task is to find maximum of n-k+1 subarrays. <br>
Note: There may be duplicates. <br>

## Idea
-------
The idea is to keep track of maximum element and its frequency in any window. <br>
Suppose the input is 1 2 3 1 4 5 2 3 6 and k is 3. Then in the first window maximum element is 3 and its frequency is 1. <br>
Slide the window by one position and if the leaving element is maximum element then reduce the maximum elements count else do nothing. <br>
If the newly encountered element is maximum element then increase its count, or if the newly encountered element is higher than the maximum element then make it the new maximum element. <br>
The problem in this approach is that while reducing the count of maximum element, if the count reaches 0, then the next higher element in the window need to be made the new maximum element. <br>
The above phenomena can happen multiple times, so better to maintain a map which contains the elements present in the current window and their frequency. <br>
As the map keeps order according to its keys, if we keep the elements as keys than maximum at each window position is the last element of the map. <br>

The above approach requires to remove the elements whose count is 0. As they are no longer present in the window. Map erase takes O(log(n)) time. <br>
This makes the total time complexity O(n log(n)). But the accepting solution time complexity is O(n). <br>

Sets can be used to over the problem facing with maps. Instead of keeping track of element and its count, all elements including its duplicates are stored in set as set of pair with first as element and second as the index, to distinguish between duplicates. This way window is a set containing truly the elements of the window. <br>


## Solution Approach 01
-----------------------
```
vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> ans;
        set<pair<int, int>> window;
        for(int i=0; i<k; ++i){
            window.insert({arr[i], i});
        }
        ans.push_back((*(--window.end())).first);
        for(int i=1; i<=n-k; ++i){
            int leave_element = arr[i-1];
            int new_encounter_element = arr[i+k-1];
            window.erase({leave_element, i-1});
            window.insert({new_encounter_element, i+k-1});
            ans.push_back((*(--window.end())).first);
        }
        return ans;
    }
```

## Notes
--------
- The time complexity is O(n). And space complexity is O(k). At any point of time set containts only k elements. At each step, one element is added and other is removed, retaining the length of set to k.
- [Hash Table vs STL Map](https://www.geeksforgeeks.org/hash-table-vs-stl-map/)

| Hash Table | STL Map |
|------------|---------|
| `unordered_map<int, int>` | `map<int, int>` |
| No order among keys | Keys are sorted in ascending order | 
| lookup is O(1) in average case and O(n) in worst case(collision) | lookup is O(log(n)) |
| insert/delete is O(1) in average case and O(n) in worst case(collision) | insert/delete is O(log(n)) + rebalanace time |
| Implemented as array of linked lists. If collision happens then the linked list is traversed to find key. Linked list stores key and value data. Hash function will return the linked list. Key value pair is inserted in linked list. If there are no collisions, then all linked lists will have only one key-value node, so operations are O(1). In case of collisions, entire linked list needs to be traversed to find the key-value pair node. | Implemented as self balancing tree most likely RB Tree as rebalancing time is O(1). In AVL Tree, rebalancing time is O(log(n)). |

## Solution Approach 02
-----------------------
```
```

## Notes
--------
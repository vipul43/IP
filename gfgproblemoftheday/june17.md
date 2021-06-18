## June 17
----------
Problem Name: Diameter of Binary Tree <br>
Problem Link: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

## Question
-----------

## Idea
-------
Diameter of any node can be diameter of the node's left child, or diameter of the node's right child or sum of depths of node's left child and right child. To find diameter, there is a need to keep track of depth of the nodes of the tree.

## Solution Approach 01
-----------------------
```
pair<int, int> depth(Node *root, int dep=0){
    if(!root) return {0, 0};
    pair<int, int> L = depth(root->left, dep+1);
    pair<int, int> R = depth(root->right, dep+1);
    return {max(L.first, R.first)+1, max(max(L.second, R.second), L.first+R.first+1)};
}

// Function to return the diameter of a Binary Tree.
int diameter(Node* root) {
    // code here
    return depth(root).second;
}
```

## Notes
--------
- Time complexity is O(V+E) where V is the number of nodes present in the tree and E is the number of edges. Since, it is a DFS algorithm(to be precise, it is post-order dfs traversal). Space complexity is O(1). Since, no additional data structure is used.
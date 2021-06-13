## June 11
---------
Problem Name: Reverse a linked list  <br>
Problem Link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

## Question
-----------
Linked List: Linked list consists of nodes where each node contains data and reference to next node of the list. <br>
The question is to reverse given linked list(To check whether a linked list is reversed print the linked list from head before reversing and after reversing. If the order of numbers printed are reverse of each other then the linked list is reversed. To print a linked list, start from head node traverse and print all nodes using next pointers till you reach null).

## Idea
-------
Naive Algorithm: <br>
1. Copy the linked list to a vector.
2. Reverse the vector.
3. Construct linked list from above reversed vector. <br>
The above algorithm takes average O(n) time but in reality the time taken is O(3\*n). Three n's each for the above points 1, 2 and 3 of naive algorithm. This might cause TLE in some coding environments. Also, some environments may prohibit using any STL containers to store the linked list to constraint the space complexity to O(1). The naive approach has space complexity O(n). <br>



## Solution Approach 01
-----------------------
```
struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    Node *ans;
    if(!head) return ans;
    vector<int> rev;
    Node *temp = head;
    while(temp){
        rev.push_back(temp->data);
        temp = temp->next;
    }
    reverse(rev.begin(), rev.end());
    ans = new Node(INT_MIN);
    temp = ans;
    for(auto &ele:rev){
        temp->next = new Node(ele);
        temp = temp->next;
    }
    return ans->next;
}
```

## Notes
--------
- Time Complexity is O(n) where n is the length of linked list. Copying entire linked list to vector is O(n). Reversing vector is O(n). And creating linked list back from reversed vector is O(n). Space complexity is O(n). A vector is used to store entire linked list.
- Took `0.37 or 0.39` on gfg for this approach.


## Solution Approach 02
-----------------------
```
struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    if(!head) return head;
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
```

## Notes
--------
- Time complexity is O(n) where n is the length of linked list. Entire linked list is traversed once. Space complexity is O(1). Only three pointers are used for storing.
- Took `0.31 or 0.32` on gfg for this approach

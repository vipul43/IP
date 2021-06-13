## June 12
---------
Problem Name: Intersection Point in Y Shapped Linked Lists  <br>
Problem Link: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

## Question
-----------

## Idea
-------

## Solution Approach 01
-----------------------
```
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node *temp = head1;
    unordered_set<Node *> st;
    while(temp){
        st.insert(temp);
        temp = temp->next;
    }
    temp = head2;
    while(temp && st.count(temp)==0){
        temp = temp->next;
    }
    return temp->data;
}
```

## Notes
--------
- Time Complexity is O(N+M) where N is length of first linked list and M is the length of second linked list. Since, we traverse through both the linked list one after the other. Space complexity is O(N) where N is the length of first linked list. As we store nodes of entire first linked list in hash table.

## Solution Approach 02
-----------------------
```
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    //marking visited nodes of first linked list
    Node *temp = head1;
    while(temp){
        temp->data+=3000;
        temp = temp->next;
    }
    //finding first marked node by travelling through second linked list
    temp = head2;
    while(temp && temp->data<2000){
        temp = temp->next;
    }
    int ans = temp->data-3000;
    //restoring the contents of first linked list
    temp = head1;
    while(temp){
        temp->data-=3000;
        temp = temp->next;
    }
    return ans;
}
```

## Notes
--------
- Time complexity is O(N+M) where N is the length of first linked list and M is the length of second linked list. Since, we traverse through both the linked list one after the other. Space complexity is O(1). Since, no additional data structure is used for storing data.
- Why only 3000? the values that can be present in any node is between -1000 and 1000 inclusive. Adding 3000, will make any value in the range distinguishable compared to the value in the range that is not added with 3000. Any value in the range after adding becomes greater than or equal to 2000. And original values can be maximum 2000. Distingushability Achieved!
- This is a very cheap trick of marking the nodes as visited. instead of using any hash table or hash map.
- First linked list is traversed again to restore the original linked list.
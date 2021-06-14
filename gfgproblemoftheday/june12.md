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
- This approach took `1.07` on geeksforgeeks.

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
- This approach took `0.53` on geeksforgeeks.

## Solution Approach 03
-----------------------
```
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node *temp1 = head1;
    int cnt1 = 0;
    while(temp1){
        cnt1++;
        temp1 = temp1->next;
    }
    Node *temp2 = head2;
    int cnt2 = 0;
    while(temp2){
        cnt2++;
        temp2 = temp2->next;
    }
    if(cnt1>=cnt2){
        temp1 = head1;
        temp2 = head2;
    } else {
        temp1 = head2;
        temp2 = head1;
    }
    //temp1 is the longer list
    int d = abs(cnt1-cnt2);
    for(int i=0; i<d; ++i){
        temp1 = temp1->next;
    }
    while(temp1 && temp2){
        if(temp1==temp2){
            return temp1->data;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}
```

## Notes
--------
- This approach took `0.91` on geeksforgeeks.

## Solution Approach 04
-----------------------
```
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    //finding length of list and creating a loop
    Node *temp1 = head1;
    int cnt1 = 1;
    while(temp1 && temp1->next){
        cnt1++;
        temp1 = temp1->next;
    }
    temp1->next = head1;
    //finding the starting point of the loop
    //from second linked list
    //Trackback in Hare and Tortoise Algorithm
    Node *temp2 = head2;
    for(int i=0; i<cnt1; ++i){
        temp2 = temp2->next;
    }
    temp1 = head2;
    while(temp1!=temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    int ans = temp1->data;
    //restoring the linked list
    temp1 = head1;
    while(temp1 && temp1->next!=head1){
        temp1 = temp1->next;
    }
    temp1->next = NULL;
    return ans;
}
```

## Notes
--------
- This approach took `0.51` on geeksforgeeks.

## Solution Approach 05
-----------------------
```
void reverseLinkedList(Node **head){
    Node *prev = NULL;
    Node *curr = *head;
    Node *next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    //linear equations
    // X(length of first linked list till intersection)+Z(length from intersection to end) = cnt1(length of first linked list)
    // Y(length of second linked list till intersection)+Z(length from intersection to end) = cnt2(length of second linked list)
    // X(length of first linked list till intersection)+Y(length of second linked list till intersection) = cnt3(length of third linked list-1)
    //getting lengths of two linked lists
    Node *temp1 = head1;
    int cnt1 = 0;
    while(temp1){
        cnt1++;
        temp1 = temp1->next;
    }
    Node *temp2 = head2;
    int cnt2 = 0;
    while(temp2){
        cnt2++;
        temp2 = temp2->next;
    }
    //reversing first linked list
    reverseLinkedList(&head1);
    //finding cnt3
    temp2 = head2;
    int cnt3 = 0;
    while(temp2){
        cnt3++;
        temp2 = temp2->next;
    }
    cnt3--;
    //solving linear equations we get
    int X = (cnt1 + cnt3 - cnt2)/2;
    int Y = (cnt2 + cnt3 - cnt1)/2;
    int Z = (cnt1 + cnt2 - cnt3)/2;
    //restoring the first linked list
    reverseLinkedList(&head1);
    temp1 = head1;
    for(int i=0; i<X; ++i){
        temp1 = temp1->next;
    }
    return temp1->data;
}
```

## Notes
--------
- This approach took `0.52` on geeksforgeeks.

## Solution Approach 06
-----------------------
```
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node *temp1 = head1;
    Node *temp2 = head2;
    while(temp1!=temp2){
        temp1 = temp1->next;
        if(!temp1) temp1 = head2;
        temp2 = temp2->next;
        if(!temp2) temp2 = head1;
    }
    return temp1->data;
}
```

## Notes
--------
- This approach took `0.53` on geeksforgeeks.
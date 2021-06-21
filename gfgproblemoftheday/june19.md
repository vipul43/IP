## June 19
---------
Problem Name: Queue using stack <br>
Problem Link: https://practice.geeksforgeeks.org/problems/queue-using-stack/1

## Question
-----------

## Idea
-------

## Solution Approach 01
-----------------------
```
class Queue {
    stack<int> input, output;
    public:
        void enqueue(int x) {
            input.push(x);
        }
        int dequeue() {
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            int temp = output.top(); output.pop();
            while(!output.empty()){
                input.push(output.top());
                output.pop();
            }
            return temp;
        }
};
```

## Notes
--------
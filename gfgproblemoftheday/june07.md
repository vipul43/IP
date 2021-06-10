## June 07
---------
Problem Name: Spirally traversing a matrix  <br>
Problem Link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

## Question
-----------

## Idea
-------

## Solution Approach 01
-----------------------
```
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    // code here 
    int posX=0;
    int posY=0;
    vector<int> arr(r*c, 0);
    int idx = 0;
    while(idx<r*c){
        int i, j;
        for(j=posY; j<c-posY; ++j){
            arr[idx++] = matrix[posX][j];
        }
        if(idx>=r*c) break;
        --j;
        for(i=posX+1; i<r-posX; ++i){
            arr[idx++] = matrix[i][j];
        }
        if(idx>=r*c) break;
        --i;
        for(int j=c-posY-2; j>=posY; --j){
            arr[idx++] = matrix[i][j];
        }
        if(idx>=r*c) break;
        for(int i=r-posX-2; i>=posX+1; --i){
            arr[idx++] = matrix[i][posY];
        }
        if(idx>=r*c) break;
        posX++;
        posY++;
    }
    return arr;
}
```

## Notes
--------
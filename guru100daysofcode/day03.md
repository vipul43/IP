## Day0
--------
Problem name: Rotten Oranges <br>
Problem link: https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1#

## Question
-----------
There are rotten, fresh and no tomato zones in a grid. The rotten tomatoes infect fresh tomatoes that are around it in four directions. If there is no tomato between rotten tomato and fresh tomato, then the fresh tomato does not get rotten by that tomato. Minimum time it takes to turn all fresh tomatoes in the grid to rotten tomatoes is the question. If this cannot be achieved then -1 needs to be returned.

## Idea
-------
First Idea is to iterate over all rotten tomatoes and start the rottening making the current rotten tomato as the sole spreader. And the rottening is spread calculating the time taking to rot each fresh tomato, till the spread is possible. While spreading all the adjacent fresh tomatoes are rottened and their time of rotting is stored. This times is stored making each rotten tomato as the sole spreader. Minimum of all time matrices at each position gives the least possible spread time of each fresh tomato. If the time matrix is initialized to infinity, then after the algorithm the positions that are non-reachable from rotten tomatoes remain infinity. If position of any fresh tomato has infinity then -1 needs to be returned. Else the maximum of all cells excluding the infinity needs to be returned. <br>
The above approach fails as the time complexity is O(n*m*n). Applying BFS takes O(n) and it needs to applied to all n*m cells if the cell has a rotten tomato. Space complexity is O(n*m) for the time matrix and queue. <br>
The trick here is that BFS need not be run on all rotten tomatoes independently. The spread takes place as each rotten tomato as center simultaneously and in level order fashion. So, one BFS for all the rotten tomatoes would suffice. <br>

## Solution Approach 01
-----------------------
```
pair<int, int> operator+(const pair<int, int> &l, const pair<int, int> &r){   
    return {l.first+r.first, l.second+r.second};                                
}

bool operator==(const pair<int, int> &l, const pair<int, int> &r){
    return (l.first==r.first && l.second==r.second);
}

int orangesRotting(vector<vector<int>>& grid) {
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(grid[i][j]==2){
                vis[i][j]=1;
                q.push({i, j});
            }
        }
    }
    pair<int, int> null = {-1, -1};
    q.push(null);
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dep = -1;
    while(!q.empty()){
        pair<int, int> temp = q.front(); q.pop();
        if(temp==null){
            dep++;
            q.push(null);
            if(q.front()==null) break;
            else continue;
        }
        grid[temp.first][temp.second] = 2;
        for(auto dir:dirs){
            pair<int, int> pos = temp+dir;
            if(pos.first>=0 && pos.first<n && pos.second>=0 && pos.second<m &&
                grid[pos.first][pos.second]==1 && vis[pos.first][pos.second]==0){
                vis[pos.first][pos.second] = 1;
                q.push(pos);
            }
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(grid[i][j]==1){
                return -1;
            }
        }
    }
    return dep;
}
```

## Notes
--------
- Time complexity is O(n*m) visiting each cell once. Total atmost n*m ce;lls are visited. Space complexity is also O(n*m) as atmost all cells enter BFS queue.
- Don't use maps for keeping track of visited nodes, <s>`map<pair<int, int>, int> vis`</s> instead use <strong>`vector<vector<int, int>> vis(n, vector<int>(m, 0))`</strong>
- Don't use pair of pair and int queues to keep track of depth, <s>`queue<pair<int, int>, int>`</s> instead use <strong>`queue<int, int>`</strong> along with null units to signify each level, and if two nulls are encountered consecutively, terminate the traversal.
- Use operator overloading in case of pairs, decreases runtime.


## Solution Approach 02
-----------------------
```
```

## Notes
--------
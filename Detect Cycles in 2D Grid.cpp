//Regular DFS
//T.C : O((m*n*4)~O(m*n)
//S.C : O(m*n)
class Solution {
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};
public:
int m, n;
bool dfs(vector<vector<char>>& grid, vector<int> prev, int i, int j, vector<vector<bool>>& visited){
    visited[i][j] = true;

    for(auto& dir: directions){
        int new_i = i + dir[0];
        int new_j = j + dir[1];

        if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)continue;

        if(new_i == prev[0] && new_j == prev[1])continue;
    
        if(grid[new_i][new_j] != grid[i][j])continue;

        if(visited[new_i][new_j])return true;

        if(dfs(grid, {i,j}, new_i, new_j,visited))return true;
    }
    return false;
}
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    if(dfs(grid, {-1, -1}, i, j, visited))return true;
                }
            }
        }
    return false;}
};

//Regular BFS
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};
public:
int m, n;
bool bfs(vector<vector<char>>& grid,int i, int j, vector<vector<bool>>& visited){
 queue<tuple<int,int,int,int>> que;

 que.push({i, j, -1,-1});
 visited[i][j] = true;

 while(!que.empty()){
    auto [curr_i, curr_j, prev_i, prev_j] = que.front();
    que.pop();

    for(auto& dir : directions){
        int new_i = curr_i + dir[0];
        int new_j = curr_j + dir[1];

        if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] == grid[curr_i][curr_j]){
            if(new_i == prev_i && new_j == prev_j)continue;

            if(visited[new_i][new_j])return true;

            visited[new_i][new_j] = true;

            que.push({new_i, new_j, curr_i, curr_j});
        }
    }
 }
    return false;
}
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    if(bfs(grid,i, j, visited))return true;
                }
            }
        }
    return false;}
};

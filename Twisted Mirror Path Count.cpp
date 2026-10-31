//T.C : O(m*n*2)~O(m*n)
//S.C : O(m*n*2)~O(m*n)
class Solution {
public:
int LEFT = 0; //arrived at the current cell from left cell(it means it was moving towards right)
int UP = 1; //arrived at the current cell from up cell(it means it was moving towards down)
int MOD = 1e9 + 7;
int m;
int n;
//memoization t[i][j]={-1,-1}
int solve(vector<vector<int>>& grid, int i, int j, int cameFrom, vector<vector<array<int,2>>>& t){
    if(i >= m || j >= n)return 0;
    if(i == m-1 && j== n-1)return 1;
    if(t[i][j][cameFrom] != -1)return t[i][j][cameFrom];
    if(grid[i][j]==1){
        if(cameFrom == LEFT){
            return t[i][j][cameFrom] = solve(grid, i+1, j, UP,t);
        }else{
            return t[i][j][cameFrom] = solve(grid, i, j+1, LEFT,t);
        }
    }

    //grid[i][j] = 0
    int totalPathCounts = 0;
    totalPathCounts = (totalPathCounts + solve(grid, i, j+1, LEFT,t)) % MOD;
    totalPathCounts = (totalPathCounts + solve(grid, i+1, j, UP,t)) % MOD;

    return t[i][j][cameFrom] = totalPathCounts; 
}
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<array<int,2>>> t(m+1,vector<array<int,2>>(n, {-1,-1}));
        return solve(grid, 0, 0, LEFT, t);
    }
};

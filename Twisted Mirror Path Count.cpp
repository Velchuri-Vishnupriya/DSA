//Approach-1 - Recursion + Memoization
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

//Approach-2 - Bottom Up
//Bottom Up 
//T.C : O(m*n*2)~O(m*n)
//S.C : O(m*n*2)~O(m*n)
class Solution {
public:
int LEFT = 0; //arrived at the current cell from left cell(it means it was moving towards right)
int UP = 1; //arrived at the current cell from up cell(it means it was moving towards down)
int MOD = 1e9 + 7;
int m;
int n;
int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> t(m,vector<vector<int>>(n, vector<int>(2,0)));

        t[0][0][LEFT] = 1;

        //Prefill the 0th row: one way to reach it is from left cell
        for(int col = 1; col < n; col++){
            t[0][col][LEFT] = 1;
            if(grid[0][col] == 1)break;
        }

        //Prefill the 0th col: one way to reach it is from UP cell
        for(int row = 1; row < m; row++){
            t[row][0][UP] = 1;
            if(grid[row][0] == 1)break;
        } 

        //Fill the remaining cells in t
        for(int row=1; row<m; row++){
            for(int col=1; col<n; col++){
                
                //entering from left cell(row,col-1)
                if(grid[row][col-1] == 1){
                    t[row][col][LEFT] = t[row][col-1][UP];
                }else{
                    t[row][col][LEFT] = (t[row][col-1][LEFT] +
                    t[row][col-1][UP]) % MOD;  
                }

                //entering from up cell
                if(grid[row-1][col] == 1){
                    t[row][col][UP] = t[row-1][col][LEFT];
                }else{
                    t[row][col][UP] = (t[row-1][col][LEFT] +
                    t[row-1][col][UP]) % MOD;
                }
            }
        }       
   return (t[m-1][n-1][LEFT] + t[m-1][n-1][UP]) % MOD; 
   }
};

//Approach-3 -Bottom Up directly mapped from Recursion code
//T.C : O(m*n*2)~O(m*n)
//S.C : O(m*n*2)~O(m*n)
class Solution {
public:
int LEFT = 0; //arrived at the current cell from left cell(it means it was moving towards right)
int UP = 1; //arrived at the current cell from up cell(it means it was moving towards down)
int MOD = 1e9 + 7;
int m;
int n;
int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> t(m+1,vector<vector<int>>(n+1, vector<int>(2,0)));

for(int i=m-1; i>=0; i--){
    for(int j=n-1; j>=0; j--){
        for(int cameFrom=0; cameFrom<2; cameFrom++){
            if(i == m-1 && j== n-1)
            {   t[i][j][cameFrom] = 1;
                continue;
            }

            if(grid[i][j] == 1){
                if(cameFrom == 0){
                    t[i][j][cameFrom] = t[i+1][j][1];
                }else{
                    t[i][j][cameFrom] = t[i][j+1][0];
                }
                continue;
            }

            int totalPaths = 0;
            totalPaths = (totalPaths + t[i][j+1][0]) % MOD;
            totalPaths = (totalPaths + t[i+1][j][1]) % MOD;

            t[i][j][cameFrom] = totalPaths;
        }
    }
}
   return t[0][0][0];
    }
};

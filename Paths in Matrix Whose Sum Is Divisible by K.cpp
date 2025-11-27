//Recurrsion + Memoization
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
public:
const int M = 1e9;
int m,n;
vector<vector<vector<int>>> t;
int solve(int i, int j, int currSum, vector<vector<int>>& grid, int k){
    if(i >= m || j >= n) return 0;

    if(i == m-1 && j == n-1) return (currSum + grid[i][j]) % k ==0;

    if(t[i][j][currSum] != -1) return t[i][j][currSum];
    int down = solve(i+1, j, (currSum + grid[i][j])%k, grid, k);
    int right = solve(i, j+1, (currSum + grid[i][j])%k, grid, k);

    return t[i][j][currSum] = (down + right) % M;
}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
    
    m = grid.size();
    n = grid[0].size();
    t.assign(m,vector<vector<int>>(n, vector<int>(k,-1)));
    return solve(0,0,0,grid,k);
    }
};

//Bottom-Up
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
public:
    int M = 1e9 + 7;

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> t(m+1, vector<vector<int>>(n+1, vector<int>(k, 0)));

        // Base case at destination
        for (int remain = 0; remain < k; remain++) {
            t[m-1][n-1][remain] = ((remain + grid[m-1][n-1]) % k == 0);
        }

        // Bottom-up DP
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                
                if (i == m-1 && j == n-1) continue;

                for (int remain = 0; remain < k; remain++) {
                    int R = (remain + grid[i][j]) % k;

                    int down = (i+1 < m) ? t[i+1][j][R] : 0;
                    int right = (j+1 < n) ? t[i][j+1][R] : 0;

                    t[i][j][remain] = (down + right) % M;
                }
            }
        }

        return t[0][0][0];
    }
};

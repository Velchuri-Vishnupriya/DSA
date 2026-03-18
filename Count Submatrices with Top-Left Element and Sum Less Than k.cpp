//Approach 1 (TLE)
//T.C : O(m*n*m)
//S.C : O(m*n)
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {

        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> grid_row_sum(m, vector<int>(n,0));
        vector<vector<int>> grid_col_sum(m, vector<int>(n,0));

        grid_row_sum[0][0] = grid[0][0];
        grid_col_sum[0][0] = grid[0][0];   // fixed typo

        // grid_row_sum
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;

                if(j == 0)
                    grid_row_sum[i][j] = grid[i][j];
                else
                    grid_row_sum[i][j] = grid_row_sum[i][j-1] + grid[i][j];
            }
        }

        // grid_col_sum
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                if(i == 0 && j == 0) continue;

                if(i == 0)
                    grid_col_sum[i][j] = grid[i][j];
                else
                    grid_col_sum[i][j] = grid_col_sum[i-1][j] + grid[i][j];
            }
        }

        vector<vector<bool>> visited(m, vector<bool>(n,false));

        int count = 0;
        int sum = grid[0][0];

        (sum <= k) ? count += 1 : count += 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(j + 1 < n) {
                    int row = i;
                    int col = j + 1;

                    if(visited[row][col] != true){
                        visited[row][col] = true;
                        int row_sum = grid_row_sum[row][col];
                        if(row_sum <= k) count++;
                    }
                }

                if(i + 1 < m){
                    int row = i + 1;
                    int col = j;

                    if(!visited[row][col]){
                        int col_sum = grid_col_sum[row][col];
                        if(col_sum <= k) count++;
                        visited[row][col] = true;
                    }
                }

                if(i + 1 < m && j + 1 < n){
                    int col = j + 1;
                    int row = i + 1;

                    if(!visited[row][col]){
                        visited[row][col] = true;

                        int diag_sum = 0;
                        for(int x = 0; x <= row; x++){   // fixed shadowing
                            diag_sum += grid_row_sum[x][col];
                        }

                        if(diag_sum <= k) count++;
                    }
                }
            }
        }

        return count;
    }
};

//Approach - 2 (Optimal)
//T.C : O(m*n*)
//S.C : O(1)
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {

        int m = grid.size(), n = grid[0].size();

        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i-1 >= 0){
                    grid[i][j] += grid[i-1][j]; // top ele added
                }
                if(j-1 >= 0){
                    grid[i][j] += grid[i][j-1]; //left ele
                }
                if(i-1 >= 0 && j-1 >= 0){
                    grid[i][j] -= grid[i-1][j-1];
                }
                if(grid[i][j] <= k){
                    count++;
                }else{
                    break;
                }
            }
        }
    return count;}
};

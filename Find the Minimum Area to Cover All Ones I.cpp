//T.C : O(m*n)
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[m-1].size();

        int maxRow = -1;
        int minRow = m;
        int minCol = n;
        int maxCol = -1;

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1){
                    maxRow = max(maxRow,row);
                    minRow = min(minRow, row);
                    maxCol = max(maxCol,col);
                    minCol = min(minCol, col);
                }
            }
        }
        return (maxRow - minRow + 1)*(maxCol - minCol + 1);
    }
};

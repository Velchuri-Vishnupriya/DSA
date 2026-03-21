//T.C : O(k^2)
//S.C : O(1)
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = 0; i < k/2; i++){//O(k/2)
            int top = x + i;
            int bottom = x + k - 1 - i;

            for(int col = 0; col < k; col++){//O(k)
                swap(grid[top][col+y], grid[bottom][col+y]);
            }
        }
    return grid;}
};

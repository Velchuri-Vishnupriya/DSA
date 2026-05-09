//T.C : O(m*n)
//S.C : O(m+n)

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for(int layer = 0; layer < layers; layer++) {

            vector<int> nums;

            int top = layer;
            int bottom = m - layer - 1;
            int left = layer;
            int right = n - layer - 1;

            // top row
            for(int j = left; j <= right; j++) {
                nums.push_back(grid[top][j]);
            }

            // right column
            for(int i = top + 1; i <= bottom - 1; i++) {
                nums.push_back(grid[i][right]);
            }

            // bottom row
            for(int j = right; j >= left; j--) {
                nums.push_back(grid[bottom][j]);
            }

            // left column
            for(int i = bottom - 1; i >= top + 1; i--) {
                nums.push_back(grid[i][left]);
            }

            int len = nums.size();

            int normalized_k = k % len;

            rotate(nums.begin(),
                   nums.begin() + normalized_k,
                   nums.end());

            int idx = 0;

            // put back top row
            for(int j = left; j <= right; j++) {
                grid[top][j] = nums[idx++];
            }

            // put back right column
            for(int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = nums[idx++];
            }

            // put back bottom row
            for(int j = right; j >= left; j--) {
                grid[bottom][j] = nums[idx++];
            }

            // put back left column
            for(int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = nums[idx++];
            }
        }

        return grid;
    }
};

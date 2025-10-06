//T.C : O(m * n)
//S.C : O(m * n)
class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j, int prev) {
        int m = heights.size();
        int n = heights[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (visited[i][j]) return;
        if (heights[i][j] < prev) return;

        visited[i][j] = true;
        dfs(heights, visited, i + 1, j, heights[i][j]);
        dfs(heights, visited, i - 1, j, heights[i][j]);
        dfs(heights, visited, i, j + 1, heights[i][j]);
        dfs(heights, visited, i, j - 1, heights[i][j]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific: left + top borders
        for (int i = 0; i < m; i++)
            dfs(heights, pacific, i, 0, heights[i][0]);
        for (int j = 0; j < n; j++)
            dfs(heights, pacific, 0, j, heights[0][j]);

        // Atlantic: right + bottom borders
        for (int i = 0; i < m; i++)
            dfs(heights, atlantic, i, n - 1, heights[i][n - 1]);
        for (int j = 0; j < n; j++)
            dfs(heights, atlantic, m - 1, j, heights[m - 1][j]);

        // Intersection of reachable cells
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};

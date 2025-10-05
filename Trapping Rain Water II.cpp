//T.C : O(m*n * log(m*n))
//S.C : O(m*n)
class Solution {
public:
    typedef pair<int, pair<int, int>> PP;
    vector<vector<int>> directions = {{0, -1},{0, 1},{-1, 0},{1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        priority_queue<PP, vector<PP>, greater<PP>> boundaryCells;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // leftmost and rightmost columns
        for (int row = 0; row < m; row++) {
            for (int col : {0, n - 1}) {
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        // topmost and bottommost rows
        for (int col = 0; col < n; col++) {
            for (int row : {0, m - 1}) {
                if (!visited[row][col]) {
                    boundaryCells.push({heightMap[row][col], {row, col}});
                    visited[row][col] = true;
                }
            }
        }

        int water = 0;
//T.C : O(m*n * log(m*n))
//S.C : O(m*n)
        while (!boundaryCells.empty()) {
            PP p = boundaryCells.top();
            boundaryCells.pop();//O(m*n)

            int height = p.first;
            int i = p.second.first;
            int j = p.second.second;

            // check four directions
            for (auto& it : directions) {
                int i_ = i + it[0];
                int j_ = j + it[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                    visited[i_][j_] = true;
                    // trapped water
                    water += max(0, height - heightMap[i_][j_]);
                    // push new boundary with max height
                    boundaryCells.push({max(height, heightMap[i_][j_]), {i_, j_}});//O(m*n)
                }
            }
        }

        return water;
    }
};

//T.C: O((m*n)*k^2)
//S.C: O(k*k)
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1,0));

        for(int i = 0; i <= m-k; i++){//O(m-k)
            for(int j =0; j <= n-k; j++){//O(n-k)
                int i_ = i+k-1;
                int j_ = j+k-1;

                unordered_set<int> distinctValues;  // Use set to store distinct values

                for(int row = i; row <= i_; row++){
                    for(int col = j; col <= j_; col++){
                        distinctValues.insert(grid[row][col]);  // Insert into set
                    }
                }

                // Convert set to vector for easier processing
                vector<int> values(distinctValues.begin(), distinctValues.end());

                if(values.size() <= 1) {
                    ans[i][j] = 0;  // 0 or 1 element, no distinct pairs
                    continue;
                }

                int min_diff = INT_MAX;
                
                for(int _i = 0; _i < values.size(); _i++){
                    for(int _j = _i+1; _j < values.size(); _j++){
                        min_diff = min(min_diff, abs(values[_j] - values[_i]));
                        if(min_diff == 0) break;  // Early exit
                    }
                    if(min_diff == 0) break;
                }

                ans[i][j] = min_diff;
            }
        }
        return ans;
    }
};

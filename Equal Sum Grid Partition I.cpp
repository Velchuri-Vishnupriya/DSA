//T.C : O(2*m*n) ~ O(m*n)
//S.C : O(1)
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long  totalSum = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                totalSum += grid[i][j];
            }
        }

        //row section check
        long long sum = 0;
        for(int i = 0; i < m-1; i++){
            for(int j = 0; j < n; j++){
                sum += grid[i][j];
            }
            if(sum == (totalSum - sum)) return true;
        }

        //col section check
        sum = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < m; j++){
                sum += grid[j][i];
            }
            if(sum == (totalSum - sum)) return true;
        }
        return false;
    }
};

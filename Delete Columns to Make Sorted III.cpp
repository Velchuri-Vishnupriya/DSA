//LIS variant
//T.C : O(cols*cols*rows)
//S.C : O(cols)
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();

        // dp[j] = max columns kept if column j is kept last
        vector<int> dp(cols, 1);

        int maxKept = 1;

        for (int j = 0; j < cols; j++) {//len of str
            for (int i = 0; i < j; i++) {

                bool canKeep = true;

            
                for (int r = 0; r < rows; r++) {
                    if (strs[r][i] > strs[r][j]) {
                        canKeep = false;
                        break;
                    }
                }

                if (canKeep) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            maxKept = max(maxKept, dp[j]);
        }
        return cols - maxKept;
    }
};

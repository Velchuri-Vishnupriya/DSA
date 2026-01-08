//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int dp[501][501];
    int m, n;
    const int NEG = -1e9;

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i == m || j == n) return NEG;

        if (dp[i][j] != NEG) return dp[i][j];

        int val = nums1[i] * nums2[j];

        int take_i_j = val + max(0, solve(nums1, nums2, i+1, j+1));
        int take_i   = solve(nums1, nums2, i+1, j);
        int take_j   = solve(nums1, nums2, i, j+1);

        return dp[i][j] = max({val, take_i_j, take_i, take_j});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();

        for(int i=0;i<501;i++)
            for(int j=0;j<501;j++)
                dp[i][j] = NEG;

        return solve(nums1, nums2, 0, 0);
    }
};

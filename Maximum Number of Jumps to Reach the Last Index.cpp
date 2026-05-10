//Bottom - Up
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n,-1);

        dp[0] = 0;

        for(int j=0; j<n; j++){
            for(int i=0; i<j; i++){
                if(abs(nums[i] - nums[j]) <= target && dp[i] != -1){
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
    return dp[n-1];
    }
};

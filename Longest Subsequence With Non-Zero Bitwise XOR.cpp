//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int maxXor = 0;
        int n = nums.size();
        bool hasNonZero = false;

        for (int num : nums) {
            maxXor ^= num;

            if (num != 0) {
                hasNonZero = true;
            }
        }

        if (maxXor != 0)
            return n;

        if (hasNonZero)
            return n - 1;

        return 0;
    }
};

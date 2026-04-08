//Brute Force
//T.C : O(Q*n)
//S.C : O(1)
class Solution {
public:
    int MOD = 1e9 + 7;
    typedef long long ll;
    
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto& query : queries) {//O(Q)
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];
            
            for (int i = l; i <= r; i += k){//max - O(n)
                nums[i] = (1LL * nums[i] * v) % MOD;
            }
        }

            int ans = 0;
        for (auto& val : nums) {
            ans ^= val;
        }
        
        
        return ans;
    }
};

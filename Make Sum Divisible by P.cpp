//T.C : O(n)
//S.C: O(1)
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int SUM = 0;
        int n = nums.size();

        for(int& num : nums){
            SUM = (SUM + num) % p;
        }

        int target = SUM % p;

        if(target == 0) return 0;

        unordered_map<int,int> mp; //prev sum % p will be stored

        long long curr = 0;
        mp[0] = -1;
        int result = INT_MAX;

        for(int j = 0; j < n; j++){
            curr = curr + 1LL * nums[j];
            int toFind = (curr - target + p) % p;
            if(mp.count(toFind)){
                result = min(result, j - mp[toFind]);
            } 
            mp[curr % p] = j;
        }
    return result == n ? -1 : result;
    }
};

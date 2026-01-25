//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(begin(nums), end(nums)); //O(nlogn)
        int res = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){//O(n)
            int minEl = nums[i];
            int maxEl = i + k - 1 < n ? nums[i+k-1] : INT_MAX;
            res = min(maxEl-minEl, res);
        }
        return res;
    }
};

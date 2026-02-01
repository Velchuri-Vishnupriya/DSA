//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = nums[0];
        sort(nums.begin() + 1, nums.end());
        return first + nums[1] + nums[2];
    }
};

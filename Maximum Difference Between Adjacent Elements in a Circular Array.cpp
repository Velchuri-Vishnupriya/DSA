//T.C: O(n)
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int diff = INT_MIN;
        int n = nums.size();
        for(int i=1; i<n; i++){
            diff = max(diff, abs(nums[i]-nums[i-1]));
        }
        diff = max(diff , abs(nums[n-1] - nums[0]));
    return diff;}
};

//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(begin(nums), end(nums));

        int n = nums.size();
        int minDiff = INT_MAX;

        for(int i = 0; i < n-1; i++){
minDiff = min(minDiff, nums[i+1] - nums[i]);
        }

        for(int i = 0; i < n-1; i++){
            if(nums[i+1] - nums[i] == minDiff){
                ans.push_back({nums[i], nums[i+1]});
            }
        }

        return ans;
    }
};

//T.C : O(n)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_val = *max_element(begin(nums), end(nums));
        int j = 0;
        int res = 0;
        int count = 0;
        while(j < n){
            if(nums[j] == max_val){
count++;
            }
            else{
                res = max(res,count);
                count = 0;
            }
            j++;
        }
      return max(res,count); }
};

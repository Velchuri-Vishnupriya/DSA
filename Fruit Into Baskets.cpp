//T.C : O(n) --> Khandani sliding window
class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int,int> mp;
        int res = INT_MIN;
        while(j < n){
            mp[nums[j]]++;
            if(mp.size() > 2){
mp[nums[i]]--;
if(mp[nums[i]] <= 0) mp.erase(nums[i]);
i++;
            res = max(j - i ,res);  }
          j++;
        }
    return max(res, j - i);}
};

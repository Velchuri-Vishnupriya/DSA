//T.C : O(n)
//S.C : O(1) -->vector[10001] is constant space
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool> V(10001 , false);
        int n = nums.size();
        int res = INT_MIN;
        int sum = 0;
        int left  = 0;
        //Total = O(n) + O(n)
        for(int i = 0; i < n; i++){//O(n)
            while(V[nums[i]]){//O(n)--> the pointer left moves only forward so in total it is O(n)
V[nums[left]] = false;
sum -= nums[left];
left++;
            }
sum += nums[i];
res = max(res , sum);
V[nums[i]] = true;
        }
   return res;}
};

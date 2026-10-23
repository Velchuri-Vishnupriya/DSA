//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
      int n = nums.size();
      int K = -1;

      for(int i=0; i<n; i++){
        if(nums[i] != i) K= K&nums[i];
      }
      return max(K,0);
       }
};

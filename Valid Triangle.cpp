//Approach - 1
//Using lower_bound
//T.C : O(n^2 * log n)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
   sort(nums.begin(), nums.end());

   int n = nums.size();

   int count = 0;

   for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
auto it = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);
int k = it - nums.begin();
count ++ (k - (j + 1));
    }
   }
  return count;  }
};

//Approach - 2
//T.C : O()

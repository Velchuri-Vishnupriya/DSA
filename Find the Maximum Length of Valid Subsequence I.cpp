//Approach - 1
//T.C : O(n)
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evens = 0;
        int odds = 0;
        for(auto& it : nums){
            if(it % 2 == 0) evens++;
            else odds++;
        }
        int even_odd_max = max(evens , odds);
        int parity = nums[0] % 2;
        int alt = 1;
        for(int i=1; i < nums.size(); i++)
        {
            int currparity = nums[i]%2;
if(currparity != parity) {
    alt++;
    parity = currparity;
       }
        }
        return max(even_odd_max , alt );
    }
};


//Approach - 2
//Recurrsion
//T.C : O(n)
//This prblm is LIS variant
//Solving by using LIS(longest increasing subsequence)
class Solution {
public:

int LIS(vector<int>& nums, int i, int prev, int mod){
if(i >= nums.size()){
    return 0;
}

    int take = 0;
    int skip = 0;

    //take
    if(prev == -1 || (nums[prev] + nums[i])%2 == mod){
        take = 1 + LIS(nums, i+1, i, mod);
    }

    //skip
    skip = LIS(nums, i+1, prev, mod);

    return max(take , skip);
}
    int maximumLength(vector<int>& nums) {
      int n = nums.size();

      int maxlen = 0;

      maxlen = max(maxlen , LIS(nums, 0, -1, 0)); //%2 == 0
      maxlen = max(maxlen , LIS(nums, 0, -1, 1)); //%2 == 1
   
   return maxlen;
    }
};

//Approach -3
//

//T.C: O(n*log n)
//S.C: O(n)

class Solution {
public:
 const int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
      int n = nums.size();
      //s1:sort
      sort(begin(nums),end(nums));

//pre-compute power
vector<int>power(n);
power[0]=1;
for(int i=1;i<n;i++){
    power[i]=(power[i-1]*2)%MOD;
}

      //l=0 r =n-1;
      int l = 0;
      int r = n-1;
      int res = 0;
      while(l<=r){
        if(nums[l]+nums[r]<=target){
            res= (res + power[r-l]) % MOD;
            l++;
        }
        else r--;
      }
      return res;
    }
};

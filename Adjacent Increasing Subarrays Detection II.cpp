//T.C : O(n*log n)
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
      int l = 1;
      int n = nums.size();
      int r = n/2;
      int ans = 0;
      while(l <= r){//log(n/2)
        bool isValid = false;

        int currlen = 1;
        int prevlen = 0;
        
        int k = l + (r - l)/2;
        
        for(int i = 1; i < n; i++){//O(n)
            if(nums[i] > nums[i-1]) currlen++;
            else{
                prevlen = currlen;
                currlen = 1;
            }
            if(currlen >= 2*k) {isValid = true; break;}
            if(min(currlen, prevlen) >= k) {isValid = true; break;}
        }

        if(isValid){
            ans = k;
            l = k + 1;
        }else{
            r = k - 1;
        }
      }
    return ans;}
};

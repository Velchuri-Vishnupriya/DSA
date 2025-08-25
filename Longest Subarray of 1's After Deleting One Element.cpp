//Brute Force
//T.C : O(n^2) - TLE
class Solution {
public:
int n;

int findMax(vector<int>& nums, int idx){
    int currlen = 0;
    int maxlen = 0;
    for(int i=0; i<n; i++){
        if(i == idx) continue;

        if(nums[i] == 1){
            currlen++;
        }
        else{
            maxlen = max(currlen, maxlen);
            currlen = 0;
        }
            }
                return max(maxlen,currlen);
}
    int longestSubarray(vector<int>& nums) {
        n = nums.size();

        int result = 0;
int cntzeros = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                cntzeros++;
                result = max(result,findMax(nums,i));
            }
        }

   return (cntzeros > 0) ? result : n-1;
   }
};

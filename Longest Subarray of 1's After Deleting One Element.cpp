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

//Sliding Window
//T.C : O(n)
class Solution {
public:
int n;
    int longestSubarray(vector<int>& nums) {
        n = nums.size();

        int result = 0;
int cntzeros = 0;
int i = 0;
        for(int j = 0; j < n; j++){
            if(nums[j] == 0){
                cntzeros++;
            }
            while(cntzeros > 1){
                if(nums[i] == 0) cntzeros--;
                i++;
            }
        result = max(result, j - i);
        }

   return result;
   }
};

//Sliding Window - modified version 
//T.C : O(n)
class Solution {
public:
int n;
    int longestSubarray(vector<int>& nums) {
        n = nums.size();

        int result = 0;
        int last_idx_zero = -1;
        int i = 0;

        for(int j = 0; j < n; j++){
            if(nums[j] == 0)
            {
        i = last_idx_zero + 1;
        last_idx_zero = j;
            }
        result = max(result, j - i);
        }
        
return result;
   }
};

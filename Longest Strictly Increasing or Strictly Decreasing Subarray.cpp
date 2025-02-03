//Brute Force
//T.S:O(N^2)
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int result = 0;
        for(int i = 0; i < n; i++) {
            int increasing = 1;
            int j = i+1;
            while(j < n && nums[j] > nums[j-1]) {
                increasing++;
                j++;
            }

            int decreasing = 1;
            j = i+1;

            while(j < n && nums[j] < nums[j-1]) {
                decreasing++;
                j++;
            }

            result = max({result, increasing, decreasing});
        }

        return result;
    }
};


//Optimal Approach
//T.S: O(n)
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int dec_len=1;
        int inc_len=1;
        int n=nums.size();
        int len=1;
        int len1=1;
        for(int i=0;i<n-1;i++){
            
            if(nums[i]>nums[i+1]) len++;
            else{
                dec_len=max(dec_len,len);
                len=1;
            }
             if(nums[i]<nums[i+1]) len1++;
            else{
                inc_len=max(inc_len,len1);
                len1=1;
            }
        }
        dec_len=max(dec_len,len);
        inc_len=max(inc_len,len1);
        return max(dec_len,inc_len);
            }
};

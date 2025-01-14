//O(n)-->Time complexity
//O(1)-->Space complexity
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int splits = 0;
 long long leftsum=0;
 long long sum=0;
 long long rightsum=0;
 for(auto it:nums){
    sum+=it;
 }
 for(int i=0;i<n-1;i++){
    leftsum+=nums[i];
    rightsum=sum-leftsum;
    if(leftsum>=rightsum){
        splits++;
    }
 }

        return splits;
    }
};

//using prefix sum
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
 int n = nums.size();
        long long sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        long long psum = 0;
        for (int i = 0; i < n - 1; i++) {
            psum += nums[i];
            if (sum - psum <= psum) {
                ans++;
            }
        }
        return ans;
    }
};

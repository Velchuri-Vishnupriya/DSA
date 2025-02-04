//Brute Force
//T.S: O(n^2)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxsum=0; int sum;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n-1;i++){
sum=nums[i];
for(int j=i+1;j<n;j++){
    if(nums[j]>nums[j-1]) sum+=nums[j];
    else break;
}
     maxsum=max(maxsum,sum);  
      }
        return maxsum;
    }
};
//Optimal Approach
//T.S: O(n)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxsum=0; int sum=nums[0];
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1]){
                sum+=nums[i];
            }
            else{
                maxsum=max(maxsum,sum);
                sum=nums[i];
            }
        }
        maxsum=max(maxsum,sum);
        return maxsum;
    }
};

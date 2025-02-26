//Kaden's Alogorithm
//T.S : O(n)
//S.C: O(n)

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currMaxSum=nums[0];
        int maxSum=nums[0];
        int currMinSum=nums[0];
        int minSum=nums[0];
        for(int i=1;i<nums.size();i++){
            currMaxSum=max(nums[i],nums[i]+currMaxSum);
            maxSum=max(currMaxSum,maxSum);

             currMinSum=min(nums[i],nums[i]+currMinSum);
            minSum=min(currMinSum,minSum);
        }

        return max(maxSum,abs(minSum));
    }
};

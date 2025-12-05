//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int partitions = 0;
        int sum = accumulate(begin(nums), end(nums), 0);

        int currSum = 0;

        for(int i=0; i<n-1; i++){
            currSum += nums[i];
            int leftSubArraySum = currSum;
            int rightSubArraySum = sum - currSum;
            ((leftSubArraySum - rightSubArraySum ) %2 ==0) ? partitions+=1 : partitions+=0;
        }

    return partitions;}
};

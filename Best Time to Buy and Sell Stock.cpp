//T.C : O(n)
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int minPrice = nums[0];
        int profit = 0;

        for(int i = 1; i < nums.size(); i++){
            profit = max(profit, nums[i] - minPrice);
            minPrice = min(minPrice, nums[i]);
        }

        return profit;
    }
};

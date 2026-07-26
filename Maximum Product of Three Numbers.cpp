//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(begin(nums), end(nums), [](int& a, int& b){
            return a>b;
        });
        int n = nums.size();
        int negPrdt = nums[n-1]*nums[n-2];
        return max(negPrdt*nums[0],
        nums[0]*nums[1]*nums[2]);
    }
};

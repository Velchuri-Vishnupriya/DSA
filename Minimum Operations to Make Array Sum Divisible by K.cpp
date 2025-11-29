//T.C : O(n) - accumulating the sum
//S.C : O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = accumulate(begin(nums), end(nums), 0);
        return sum % k; 
    }
};

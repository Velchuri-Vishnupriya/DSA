//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(begin(nums), end(nums), [](int& a, int& b){
            return a>b;
        });
        int prod1 = (nums[0]-1)*(nums[1]-1);
        int n = nums.size();
        int prod2 = (nums[n-1]-1)*(nums[n-2]-1);
        return max(prod1, prod2);
    }
};

//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxRotateFunction(vector<int>& nums){
        int n = nums.size();
        int F = 0;
        int sum = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];
            F += (i*nums[i]);
        }
        int result = F;
//Formula: F(k) = F(k-1) + sum - n*nums[n-k];

        for(int k=1; k<n; k++){
            F = F + sum - n*nums[n-k];
            result = max(result, F);
        }
    return result;
    }
};

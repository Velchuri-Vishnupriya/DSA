//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int smallestMul = k;
        for(int i=0; i<n; i++){
            if(nums[i] == smallestMul){
                smallestMul += k;
            }
        }
    return smallestMul;
    }
};

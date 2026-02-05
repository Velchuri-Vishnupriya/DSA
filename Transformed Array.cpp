//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int i = 0;
        for(auto& num : nums){
            result[i] = nums[(i + ((num + 100*n) % n)) % n];
            i++;
        }

        return result;
 }

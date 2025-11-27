//T.C : O(n)
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int val = 0;  
        
        for (int b : nums) {
            val = (val * 2 + b) % 5;
            result.push_back(val == 0);
        }
        return result;
    }
};

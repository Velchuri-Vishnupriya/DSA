//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_El = *min_element(begin(nums), end(nums));
        int count = 0;
        for(auto& num : nums){
            count += (num-min_El);
        }
        return count;
    }
};

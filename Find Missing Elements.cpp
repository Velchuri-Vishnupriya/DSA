//T.C : O(max_el*n)
//S.C : O(1)
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min_ele = *min_element(nums.begin(), nums.end());
        int max_ele = *max_element(nums.begin(), nums.end());
        vector<int> missingEl;
        for(int i=min_ele+1; i<max_ele; i++){
            if(find(nums.begin(), nums.end(), i) == nums.end()){
                missingEl.push_back(i);
            }
        }
    return missingEl;
    }
};

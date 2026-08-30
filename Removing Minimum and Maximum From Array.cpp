//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        int max_el = *max_element(nums.begin(), nums.end());//O(n)
        int min_el = *min_element(nums.begin(), nums.end());//O(n)
        int min_pos = find(nums.begin(), nums.end(), min_el) - nums.begin();//O(n)
        int max_pos = find(nums.begin(), nums.end(), max_el) - nums.begin();//O(n)

        int left = min(max_pos, min_pos);
        int right = max(max_pos, min_pos);

        //both on left
        int case1 = right + 1;

        //both on right
        int case2 = n - left;

        //on different sides
        int case3 = (left+1) + (n-right);

        return min({case1, case2, case3});
    }
};

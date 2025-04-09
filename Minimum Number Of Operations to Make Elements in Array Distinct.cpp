//T.C: O(n^2)
//S.C: O(n)
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;

        while (true) {
            unordered_set<int> s(nums.begin(), nums.end());
            if (s.size() == nums.size()) break; 
            int toErase = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + toErase);
            count++;
        }

        return count;
    }
};

//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        int result = INT_MAX;

        for(int i = 0; i < n; i++) {
            auto &vec = mp[nums[i]];
            vec.push_back(i);

            if(vec.size() >= 3) {
                int size = vec.size();
                int dist = vec[size - 1] - vec[size - 3];
                result = min(result, 2*dist);
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};

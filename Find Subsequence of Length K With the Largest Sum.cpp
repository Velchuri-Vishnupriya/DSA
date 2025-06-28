class Solution {
public:
    typedef pair<int, int> P;
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<P, vector<P>> pq;
        
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        vector<P> selected;
        while (k--) {
            selected.push_back(pq.top());
            pq.pop();
        }

        // lamda function
        sort(selected.begin(), selected.end(), [](P& a, P& b) {
            return a.second < b.second;
        });

        vector<int> ans;
        for (auto& p : selected) {
            ans.push_back(p.first);
        }

        return ans;
    }
};

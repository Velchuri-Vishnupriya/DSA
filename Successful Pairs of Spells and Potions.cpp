//T.C : O((m + n)*log m)
//S.C : O(1);
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long suc) {
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs(n, 0);

        sort(potions.begin(), potions.end());
        int i = 0; 

        for (auto& num : spells) {
            long long val = ceil((long double)suc / num);  
            auto it = lower_bound(potions.begin(), potions.end(), (long long)val);
            int idx = distance(potions.begin(), it);

            if (idx < m)
                pairs[i] = m - idx; 
            else
                pairs[i] = 0;

            i++;
        }
        return pairs;
    }
};

//T.C : O(n)
const int MOD = 1e9 + 7;
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        // computing powers array
        for (int i = 0; i < 32; i++) {//O(32)
            if ((n & (1 << i)) != 0) {
                powers.push_back(1 << i);
            }
        }


        vector<int> answer;
        for (auto& it : queries) {//O(n)
            int u = it[0];
            int v = it[1];
            long prod = 1;
           for(int i = u; i <= v; i++){//O(32) if all the bits are set
            prod = (prod * powers[i]) % MOD;
           }
           answer.push_back(prod);
        }
        return answer;
    }
};

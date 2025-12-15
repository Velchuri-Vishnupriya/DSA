//T.C : O(n)
//S.C : O(1)
class Solution {
public:
const int MOD = 1e9 + 7;
    int numberOfWays(string& corridor) {
        int n = corridor.length();
        vector<int>countS;
        for(int i = 0; i < n; i++){
            if(corridor[i] == 'S')countS.push_back(i);
        }
        if(countS.size() % 2 != 0 || countS.size() < 2)return 0;
        long long ans = 1;
        int prev_end_idx = countS[1];
        for(int i = 2; i < countS.size(); i+=2){
            ans = (ans * (countS[i] - prev_end_idx)) % MOD;
            prev_end_idx = countS[i+1];
        }
      return ans;
      }
};

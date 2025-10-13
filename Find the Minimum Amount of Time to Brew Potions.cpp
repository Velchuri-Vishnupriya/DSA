//T.C : O(m*n)
//S.C : O(n)
class Solution {
public:
    long long minTime(vector<int>& skills, vector<int>& mana) {
       int n = skills.size();
       int m = mana.size();

       vector<long long> finishTime(n, 0);

       for(int j = 0; j < m; j++){//O(m)
        finishTime[0] += mana[j]*skills[0];

        for(int i = 1; i < n; i++){//O(n)
            finishTime[i] = max(finishTime[i], finishTime[i-1]) + mana[j]*skills[i];
        }

        for(int i = n-1; i > 0; i--){//O(n)
            finishTime[i - 1] = finishTime[i] - mana[j]*skills[i] * 1LL;
        }
       }
    return finishTime[n-1];}
};

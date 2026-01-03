// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    int numOfWays(int n) {
       const int MOD = 1e9 + 7;

       long long dpA = 6; //ABC variants
       long long dpB = 6; //ABA variants

       for(int row = 2; row <= n; row++){
        long long new_dpA = ((dpA % MOD)*2 + (dpB % MOD)*2) % MOD; //BAB CAB BCA BCB
        long long  new_dpB = ((dpA % MOD)*2 + (dpB % MOD)*3) % MOD; //BAB CAB BCB BAC CAC

        dpA = new_dpA;
        dpB = new_dpB;
       }
       return (int)(dpA + dpB) % MOD;
    }
};

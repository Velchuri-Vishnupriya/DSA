//Classic knapsack related problem
//T.C : O(n^2) - Top Down With Memoization
class Solution {
public:
const int MOD = 1e9 + 7;
int t[301][301];
int solve(int n, int num, int x){
    if(n < 0 ) return 0;
    if(n ==  0) return 1;
    int currPower = pow(num, x);
    if(currPower > n)return 0;
    if(t[n][num] != -1) return t[n][num];
    int take = solve(n - currPower, num+1,x);
    int skip = solve(n, num + 1, x );

    return t[n][num] = (take + skip) % MOD;
}
    int numberOfWays(int n, int x) {
        memset(t, -1, sizeof(t));
        return solve(n, 1, x);
    }
};

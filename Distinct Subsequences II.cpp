//Recursion + Memoization
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
int M = 1e9+7;
int dp[2001];
vector<int> prev; //prev[n]=last time when we saw this nth char 1-based idx
    
    int solve(int n){
        if(n == 0)return 1;
        if(dp[n] != -1){
            return dp[n];
        }
        int total = (solve(n-1)*2) % M;
        if(prev[n] != 0){
        int duplicates = solve(prev[n] - 1);
        total = (total - duplicates + M) % M;}
        return dp[n]=total;
    }
        int distinctSubseqII(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        prev.assign(n+1, 0);

        vector<int> lastSeen(26,0);
        for(int i=1; i<=n; i++){
            int idx = s[i-1]-'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }

        return (solve(n)-1) % M;
    }
};

//Bottom Up
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
int M = 1e9+7;
int dp[2001];
vector<int> prev; //prev[n]=last time when we saw this nth char 1-based idx
   int distinctSubseqII(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        prev.assign(n+1, 0);

        vector<int> lastSeen(26,0);
        for(int i=1; i<=n; i++){
            int idx = s[i-1]-'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }

        dp[0] = 1;
        for(int i=1; i<=n; i++){
            int total = (2*dp[i-1]) % M;
            if(prev[i] != 0){
                int duplicates = dp[prev[i] - 1];
                total = (total - duplicates + M ) % M; 
            }
            dp[i] = total;
        }
        return (dp[n]- 1 + M) % M;
    }
};

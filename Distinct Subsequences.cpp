//Top-Down
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
typedef unsigned long long ull;
ull dp[1001][1001];
ull solve(string& s, string& t, int m, int n){
    if(n == 0)return 1;
    if(m == 0)return 0;

    if(dp[m][n] != -1)return dp[m][n];

    if(s[m-1] == t[n-1]){
        return dp[m][n] = solve(s,t,m-1,n-1)+solve(s,t,m-1,n);
    }else{
        return dp[m][n] = solve(s,t,m-1,n);
    }
    return -1;
}
int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        memset(dp, -1, sizeof(dp));
        return solve(s,t,m,n);
    }
};

//Bottom-Up
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
typedef unsigned long long ull;
int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        //dp array
        vector<vector<ull>>dp(m+1, vector<ull>(n+1));

        //base case1
        //if(n==0) return 1
        //dp[m][0]=1
        for(int i=0; i<=m; i++){
            dp[i][0] = 1;
        }

        //base case2
        //if(m==0)return 0;
        //dp[0][m]=0
        for(int j=1; j<=n; j++){
            dp[0][j] = 0;
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; 
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
   return dp[m][n];
    }
};

//Bottom-Up with space optimization
//T.C : O(m*n)
//S.C : O(n)
class Solution {
public:
typedef unsigned long long ull;
int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        //dp array
        vector<ull> curr(n+1,0);
        vector<ull> prev(n+1,0);
        curr[0] = 1;
        prev[0] = 1;

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1] + prev[j]; 
                }else{
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
   return prev[n];
    }
};

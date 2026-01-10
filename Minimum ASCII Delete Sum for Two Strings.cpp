//Recurrsion + Memoization MLE
//T.C : O(m*n)
//S.C : O(m*n + (m+n))
class Solution {
public:
vector<vector<int>> t;
int m,n;

int solve(string s1, string s2, int i, int j){
    if(i >= m || j >= n)return 0;

    if(t[i][j] != -1) return t[i][j];

    if(s1[i] == s2[j]){
        return t[i][j] = (s1[i]) + solve(s1,s2,i+1,j+1);
    }else{
        return t[i][j] = max(solve(s1,s2,i+1,j), solve(s1,s2,i,j+1));
    }

}
    int minimumDeleteSum(string s1, string s2) {
        //find max ASCII val
        m = s1.length();
        n = s2.length();
        t.assign(m,vector<int>(n,-1));

        int LCS_Sum = solve(s1,s2,0,0);

        int totalSum = 0;

        for(auto& ch : s1){
            totalSum += static_cast<int>(ch);
        }

        for(auto& ch : s2){
            totalSum += static_cast<int>(ch);
        }

        return totalSum - 2*LCS_Sum;
    }
};

//Bottom - Up
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
     int m = s1.length();
     int n = s2.length();

     vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(s1[i] == s2[j]) dp[i][j] = s1[i] + dp[i+1][j+1];
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

       int LCS_Sum = dp[0][0];

        int totalSum = 0;

        for(auto& ch : s1){
            totalSum += static_cast<int>(ch);
        }

        for(auto& ch : s2){
            totalSum += static_cast<int>(ch);
        }

    return totalSum - 2*LCS_Sum;
    }
};

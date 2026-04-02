//Recursion + Memoization
//T.C : O(m*n*3)~O(m*n)
//S.C : O(m*n*3)~O(m*n)
class Solution {
public:
int n,m;
vector<vector<vector<int>>> dp;
int solve(vector<vector<int>>& coins, int i, int j, int k){
    if(i >= m || j >= n)return INT_MIN;

    if(dp[i][j][k] != INT_MIN)return dp[i][j][k];

    if(i == m-1 && j == n-1){
        if(coins[i][j] >= 0)return coins[i][j];
        else{
            if(k > 0){
                k--;
                return 0;
            }else{
                return coins[i][j];
            }
        }
    }

    int curr_val = coins[i][j];
    int result = INT_MIN;

    if(curr_val >= 0){
        //right
        if(j + 1 < n) result = max(result, curr_val + solve(coins,i, j+1,k));
        //down
        if(i + 1 < m) result = max(result, curr_val + solve(coins,i+1, j, k));
    }else{
        if(k > 0){
            //skipping the ele
            //right
            if(j+1 < n) result = max(result, 0 + solve(coins,i, j+1, k-1));
            //down
            if(i+1 < m) result = max(result, 0 + solve(coins, i+1, j, k-1));
        }
        if(j+1 < n) result = max(result, curr_val + solve(coins, i, j+1,k));
        if(i+1 < m) result = max(result, curr_val + solve(coins, i+1, j, k));
    }
    return dp[i][j][k] = result;
}
    int maximumAmount(vector<vector<int>>& coins) {
        this->m = coins.size();
this->n = coins[0].size();
dp.assign(m, vector<vector<int>>(n, vector<int>(3,INT_MIN)));
        return solve(coins,0,0,2);
    }
};

//Bottom Up
//T.C : O(m*n*3)~O(m*n)
//S.C : O(m*n*3)~O(m*n)
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        long long t[m][n][3];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k <=2; k++){
                    t[i][j][k] = INT_MIN;
                }
            }
        }
int i = m-1;
int j = n-1;
        if(coins[i][j] >= 0){
            t[i][j][0] = t[i][j][1] = t[i][j][2] = coins[m-1][n-1];
        }else{
            t[i][j][0] = coins[m-1][n-1];
            t[i][j][1] = 0;
            t[i][j][2] = 0;
        }

        for(i=m-1; i>=0; i--){
            for(j=n-1; j>=0; j--){
                if(i == m-1 && j == n-1)continue;
                for(int k=2; k >= 0; k--){
                long long curr_val = coins[i][j];
                long long result = INT_MIN;
                if(curr_val >= 0){
                    if(j+1 < n){
                        result = max(result, curr_val + t[i][j+1][k]);
                    }
                    if(i+1 < m){
                        result = max(result, curr_val + t[i+1][j][k]);
                    }
                }else{
                    if(k > 0){
                        if(j+1 < n){
                            result = max(result, t[i][j+1][k-1]);
                        }
                        if(i+1 < m){
                            result = max(result, t[i+1][j][k-1]);
                        }
                    }
                    if(j+1 < n){
                        result = max(result, t[i][j+1][k] + curr_val);
                    }
                    if(i+1 < m){
                        result = max(result, t[i+1][j][k] + curr_val);
                    }
                }
                t[i][j][k] = result;
            }
            }
        }

    return t[0][0][2];
    }
};

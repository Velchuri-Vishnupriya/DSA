//Recursion + Memoization
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    typedef long long ll;

    ll solve(int i, int j, vector<int>& robot, vector<int>& positions, vector<vector<ll>>& dp){
        if(i >= robot.size()) return 0;
        if(j >= positions.size()) return LLONG_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        // take
        ll take = LLONG_MAX;
        ll next = solve(i+1, j+1, robot, positions, dp);
        if(next != LLONG_MAX){
            take = abs(robot[i] - positions[j]) + next;
        }

        // skip
        ll skip = solve(i, j+1, robot, positions, dp);

        return dp[i][j] = min(take, skip);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // expand factory
        vector<int> positions;
        for(int i = 0; i < factory.size(); i++){
            int pos = factory[i][0];
            int limit = factory[i][1];

            for(int j = 0; j < limit; j++){
                positions.push_back(pos);
            }
        }

        int m = robot.size();
        int n = positions.size();

        vector<vector<ll>> dp(m, vector<ll>(n, -1));

        return solve(0, 0, robot, positions, dp);
    }
};

//Bottom Up
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
typedef long long ll;

   long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // expand factory
        vector<int> positions;
        for(int i = 0; i < factory.size(); i++){
            int pos = factory[i][0];
            int limit = factory[i][1];

            for(int j = 0; j < limit; j++){
                positions.push_back(pos);
            }
        }

        int m = robot.size();
        int n = positions.size();

        vector<vector<ll>> dp(m+1, vector<ll>(n+1, -1));

        for(int j=0; j<=n; j++){
            dp[m][j] = 0;
        }

        for(int i=0; i<m; i++){
            dp[i][n] = 1e15; // safe large value;
        }

        for(int i = m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                ll take = 1e15;
                ll next = dp[i+1][j+1];
                if(next != 1e15){
                    take = abs(robot[i] - positions[j]) + next; 
                }

                ll skip = dp[i][j+1];

                dp[i][j] = min(take, skip);
            }
        }
    return dp[0][0] >= 1e15 ? 0 : dp[0][0];
    }
};

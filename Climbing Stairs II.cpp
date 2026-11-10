//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int n;
    int t[100001];

    int solve(vector<int>& costs, int i) {
        if(i == n) return 0;
        if(t[i] != -1)return t[i];

        int j = i+1;
        int result = INT_MAX;

        if(j <= n) {
            int cost1 = costs[j-1] + pow((j-i),2);
            result = min(result, cost1 + solve(costs, j));
        }

        if(j+1 <= n) {
            int cost2 = costs[j] + pow((j-i+1),2);
            result = min(result, cost2 + solve(costs, j+1));
        }

        if(j+2 <= n) {
            int cost3 = costs[j+1] + pow((j-i+2),2);
            result = min(result, cost3 + solve(costs, j+2));
        }

        return t[i] = result;
    }

    int climbStairs(int N, vector<int>& costs) {
        n = N;
        memset(t, -1, sizeof(t));
        return solve(costs, 0);
    }
};

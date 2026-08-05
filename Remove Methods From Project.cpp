// T.C : O(V + E)
// S.C : O(V + E)

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Adjacency list
        vector<vector<int>> adj(n);
        vector<bool> suspicious(n, false);

        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        // BFS to mark all suspicious methods
        queue<int> que;
        que.push(k);
        suspicious[k] = true;

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (int &ngbr : adj[u]) {
                if (!suspicious[ngbr]) {
                    suspicious[ngbr] = true;
                    que.push(ngbr);
                }
            }
        }

        // Check if any non-suspicious method invokes a suspicious method
        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!suspicious[u] && suspicious[v]) {
                vector<int> result;
                for (int i = 0; i < n; i++)
                    result.push_back(i);
                return result;
            }
        }

        // Remove all suspicious methods
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                result.push_back(i);
        }

        return result;
    }
};

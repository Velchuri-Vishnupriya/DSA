//T.C : O(n)
//S.C : O(n)
class Solution {
public:
const static int MOD = 1e9 + 7;
typedef long long ll;
ll power(int a, int b){//O(logn)
    if(b == 0)return 1;

    ll half = power(a, b/2);
    ll result = (1LL*half*half) % MOD;
    if(b & 1){
        result = (1LL*result*a) % MOD;
    }

    return result;
} 
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n+1);

        for(auto& edge : edges){//O(n)
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n+1, false);
        queue<int> que;
        que.push(1);
        visited[1] = true;

        int depth = -1;

        while(!que.empty()){//O(n)
            int size = que.size();
            
            while(size--){
                int u = que.front();
                que.pop();
                for(auto& ngbr: adj[u]){
                    if(!visited[ngbr]){
                        visited[ngbr] = true;
                        que.push(ngbr);
                    }
                }
            }
            depth++;
        }
        return power(2, depth-1);
        }
};

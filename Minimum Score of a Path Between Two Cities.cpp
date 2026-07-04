//DFS
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
public:
void dfs(int u, unordered_map<int, vector<pair<int,int>>>& adj, vector<bool>& visited, int& result){
    visited[u]=true;
    for(auto& ngbr:adj[u]){
        int v=ngbr.first;
        int dist=ngbr.second;
        result = min(result, dist);
        if(!visited[v]){
            dfs(v, adj, visited, result);
        }
    }
    return;
}
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto& vec : roads){
            int u=vec[0];
            int v=vec[1];
            int dist=vec[2];

            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
        vector<bool> visited(n+1, false);
        int result = INT_MAX;
        dfs(1, adj, visited, result);
        return result;
    }
};

//BFS
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
public:
int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto& vec : roads){
            int u=vec[0];
            int v=vec[1];
            int dist=vec[2];

            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
        vector<bool> visited(n+1, false);
        queue<int> pq;
        pq.push(1);
        int result = INT_MAX;
        while(!pq.empty()){
            int size = pq.size();
            while(size--){
                int u = pq.front();
                pq.pop();
                visited[u]=true;
                for(auto& ngbr:adj[u]){
                    int v = ngbr.first;
                    if(!visited[v]){
                        int dist = ngbr.second;
                        result = min(result, dist);
                        pq.push(v);
                    }
                }
            }
        }      
    return result;
    }
};

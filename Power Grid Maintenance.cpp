//T.C : O((c + n) + (q * log c))
//S.C : O(n)
class Solution {
public:
int c;
void dfs(int node, unordered_map<int,vector<int>>& adj,int id, vector<int>& nodeId, unordered_map<int,set<int>>& mp, vector<bool>& visited)
{
visited[node] = true;
mp[id].insert(node);
nodeId[node] = id;

for(int& ngbr : adj[node]){
    if(!visited[ngbr]){
        dfs(ngbr, adj, id, nodeId, mp, visited);
    }
}

}
    vector<int> processQueries(int c_, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        c = c_;
        vector<bool> visited(c+1, false);
        for(auto& edge : connections){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> nodeId(c+1);
        //id -> {}
        unordered_map<int,set<int>> mp;

//O(c + n) (c = V , n = E)
        for(int node = 1; node <= c; node++){//each of the nodes are visited at max only once
            if(!visited[node]){
                int component_id = node;
                dfs(node, adj, component_id, nodeId, mp, visited);
            }
        }

        vector<int> result;

        for(auto& query : queries){//O(q * log c)
            int type = query[0]; //1,2
            int node = query[1];

            if(type == 1){
                int id = nodeId[node];
                if(mp[id].count(node)){
                    result.push_back(node);
                }else if(!mp[id].empty()){
                    result.push_back(*mp[id].begin());
                }else{
                    result.push_back(-1);
                }
            }else{
                int id = nodeId[node];
                mp[id].erase(node); //log(c)
            }
        }
   return result;
    }
};

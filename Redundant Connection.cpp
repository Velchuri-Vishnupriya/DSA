//Using DFS -Approach-1
class Solution {
public:
    bool dfs(int u, int v, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        if (u == v) return true;  
        visited[u] = true;
        for (int &ngbr : adj[u]) {
            if (!visited[ngbr]) {
                if (dfs(ngbr, v, adj, visited)) return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int n = edges.size();

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];

            vector<bool> visited(n + 1, false); 
            if (adj.count(u) && adj.count(v) && dfs(u, v, adj, visited)) {
                return {u, v};
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return {}; 
    }
};

//Usiung Topological sort-Approach-2
class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int n = edges.size();
vector<int> indegree(n+1,0);
for(int i=0;i<n;i++){
    int u=edges[i][0]; int v=edges[i][1];
    indegree[u]++;
    indegree[v]++;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
queue<int> q;
for(int i=1;i<=n;i++){
    if(indegree[i]==1) q.push(i);
}
while(!q.empty()){
    int node=q.front();
    q.pop();
    for(int& ngbr:adj[node]){
        indegree[ngbr]--;
        indegree[node]--;
        if(indegree[ngbr]==1){q.push(ngbr);}
    }
}
for(int i=n-1;i>=0;i--){
    int u=edges[i][0]; int v=edges[i][1];
    if(indegree[u]>=1 && indegree[v]>=1) return {u,v};
}
        
        return {}; 
    }
};

//Using BFS-Approach 3
class Solution {
public:
    bool bfs(int u, int v, unordered_map<int, vector<int>>& adj,vector<bool>& visited) {
        queue<int> q;
        q.push(u);
        visited[u]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto& ngbr:adj[node]){
if(ngbr==v) return true;
 else{
    if(!visited[ngbr])
    {q.push(ngbr);
    visited[ngbr]=true;
    }
            }
        }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int n = edges.size();

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];

            vector<bool> visited(n + 1, false); 
            if (adj.count(u) && adj.count(v) && bfs(u, v, adj,visited)) {
                return {u, v};
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return {}; 
    }
};

//Approach 4 - Using DSU
class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
     
     DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
        }
     }

     int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
     }

     void my_union(int x,int y){
int x_parent=find(x);
int y_parent=find(y);

if(x_parent==y_parent) return;
if(rank[x_parent]>rank[y_parent])
{parent[y_parent]=x_parent;}
     
     else if (rank[y_parent]>rank[x_parent])
     {parent[x_parent]=y_parent;}
     else{parent[x_parent]=y_parent;
     rank[y_parent]++;}
     }
};
class Solution {
public:

    vector<int> findRedundantConnection
    (vector<vector<int>>& edges) {
     
     int n=edges.size();
     DSU dsu(n);
      for(auto& edge:edges){
        int u=edge[0]; int v=edge[1];
        if(dsu.find(u)==dsu.find(v)) return {u,v};
        dsu.my_union(u,v);
      }
      return {};
    }
};


//Approach - 1 -> Using DFS
//T.C : O(V + E) - at most each node is visited once
//S.C : O(n)
class Solution {
public:
int n;
void dfs(vector<int>& edges, int node, vector<int>& dist, vector<bool>& visited){
    visited[node] = true;
    
    int v =edges[node];

    if(v != -1 && !visited[v]){
    dist[v] = 1 + dist[node];
    dfs(edges, v, dist, visited);
    }
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
      n = edges.size();

      vector<int> dist1(n, INT_MAX);
      vector<int> dist2(n, INT_MAX);  
    
    vector<bool>visited(n, false);
    
    dist1[node1] = 0;
    dist2[node2] = 0;
    
    dfs(edges, node1, dist1, visited );
    visited.clear();
    visited.resize(n,false);
    dfs(edges, node2, dist2, visited);
        
        int minDisNode = -1;
        int minDistanceTillNow = INT_MAX;
        for(int i=0; i<n; i++){
int maxD = max(dist1[i], dist2[i]);

if(minDistanceTillNow > maxD){
    minDistanceTillNow = maxD;
    minDisNode = i;
}
        }
       return minDisNode; }
};

//Approach - 1 -> Using BFS
//T.C : O(V + E) - at most each node is visited once
//S.C : O(n)
class Solution {
public:
int n;
void bfs(vector<int>& edges, int node, vector<int>& dist){
queue<int> que;
que.push(node);
vector<bool> visited(n,false);
visited[node] = true;
while(!que.empty()){
    int u = que.front();
    que.pop();
    int v = edges[u];
   if(v != -1 && !visited[v]) { dist[v] = 1 + dist[u];
    que.push(v); 
    visited[v] = true;}
}
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
      n = edges.size();

      vector<int> dist1(n, INT_MAX);
      vector<int> dist2(n, INT_MAX);  
    
    
    dist1[node1] = 0;
    dist2[node2] = 0;
    
    bfs(edges, node1, dist1);
    
    bfs(edges, node2, dist2);
        
        int minDisNode = -1;
        int minDistanceTillNow = INT_MAX;
        for(int i=0; i<n; i++){
int maxD = max(dist1[i], dist2[i]);

if(minDistanceTillNow > maxD){
    minDistanceTillNow = maxD;
    minDisNode = i;
}
        }
       return minDisNode; }
};

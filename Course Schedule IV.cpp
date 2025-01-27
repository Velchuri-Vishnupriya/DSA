//Approach -1 
//Time Limit Exceeded
class Solution{
public:
bool dfs(unordered_map<int,vector<int>>& adj,int src,
int dest,vector<bool> visited){
visited[src]=true;
if(src==dest){return true;}
bool isReacheable=false;
for(auto& adjNode:adj[src] ){
    if(!visited[adjNode]){
isReacheable=isReacheable || dfs(adj,adjNode,dest,visited);
    }
}
return isReacheable;
}
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        for(auto& edge: prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        int Q=queries.size();
        vector<bool> result(Q); 
        for(int i=0;i<Q;i++){
            int u=queries[i][0]; //src
            int v=queries[i][1]; //dest
            vector<bool> visited(numCourses,false);
result[i]=dfs(adj,u,v,visited);
        }
        return result;
    }
};

//Approach-2


//Approach-3 Topological Sort
class Solution{
public:

    vector<bool> checkIfPrerequisite(int numCourses,vector<vector<int>>& prerequisites,vector<vector<int>>& queries) {
    unordered_map<int,vector<int>>adj;
    vector<int>indegree(numCourses,0);
    for(auto& edge:prerequisites){
        int u=edge[0];int v=edge[1];
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for(int i=0;i<numCourses;i++){
        if(!indegree[i]) q.push(i);
    }
    unordered_map<int,unordered_set<int>>mp;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto& ngbr:adj[node]){
            mp[ngbr].insert(node);
            for(auto& prereq: mp[node]){
                mp[ngbr].insert(prereq);
            }
            indegree[ngbr]--;
            if(!indegree[ngbr]) q.push(ngbr);
        }
    }
    int Q=queries.size();
    vector<bool> result(Q,false);
   for(int i=0;i<Q;i++){
    int src=queries[i][0];
    int dest=queries[i][1];
    bool isReachable=mp[dest].contains(src);
    result[i]=isReachable;
   }
   return result; }
};

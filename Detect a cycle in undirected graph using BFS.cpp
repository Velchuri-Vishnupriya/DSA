class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycleDFS(vector<vector<int>> adj,int u,vector<bool>& visited){
        queue<pair<int,int>> que;
        que.push({u,-1});
        visited[u]=true;
        while(!que.empty()){
            pair<int,int> P=que.front();
            que.pop();
            int source=P.first;
            int parent=P.second;
            for(int& v:adj[source]){
                if(!visited[v]){
                    visited[v]=true;
                    que.push({v,parent});
                    }
                    else if(v != parent){
                        return true;
                    }
            }
        }
        return false;
        
    }
    bool isCycle(vector<vector<int>>& adj) {
        int v=adj.size();
         vector<bool> visited(v,false);
         for(int i=0;i<v;i++){
             if(!visited[i] && isCycleDFS(adj,i,visited)){
                 return true;
             }
         }
         return false;
    }
};

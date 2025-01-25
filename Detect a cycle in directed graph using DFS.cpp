class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCycleDFS(vector<vector<int>> adj,int u, vector<bool>visited,vector<bool> inRecurrsion){
        visited[u]=true;
        inRecurrsion[u]=true;
        for(int &v:adj[u]){
            if(!visited[v] && isCycleDFS(adj,v,visited,inRecurrsion)) return true;
            else if(inRecurrsion[v]==true) return true;
        }
       inRecurrsion[u]=false;
      return false;  
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<bool>visited(V,false);
        vector<bool> inRecurrsion(V,false);
        for(int i=0;i<V;i++){
            if(isCycleDFS(adj,i,visited,inRecurrsion) && !visited[i]){
                return true;
            }
        }
    return false; }
};

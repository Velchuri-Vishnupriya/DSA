//Solving using DFS
class Solution {
public:
bool isCycle(vector<vector<int>>& adj,int u,vector<bool>& visited,
vector<bool>& inRecursion){
    visited[u]=true;
    inRecursion[u]=true;
    for(int& v: adj[u]){
        if(inRecursion[v]) return true;
        else if(!visited[v] && isCycle(adj,v,visited,inRecursion
        )) return true;
    }
    inRecursion[u]=false;
    return false;
}
    vector<int> eventualSafeNodes
    (vector<vector<int>>& graph) {
        int V=graph.size();
        vector<bool> visited(V,false);
        vector<bool> inRecursion(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i] && isCycle (graph,i,visited,inRecursion))
      {}  }
        vector<int> safenodes;
        for(int i=0;i<V;i++){
            if(inRecursion[i]==false){
                safenodes.push_back(i);
            }
        }
        return safenodes;
    }
};

//Using BFS

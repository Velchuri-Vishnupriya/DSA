//Using DFS
//T.S : O(V+E)
class Solution {
public:
    bool BP_DFS(vector<vector<int>>& graph, int val, vector<int>& color, int colorval) {
        color[val] = colorval;
        
        for (auto& ngbr : graph[val]) {
            if (color[ngbr] == color[val]) return false;
            if (color[ngbr] == -1) {
                if (!BP_DFS(graph, ngbr, color, 1 - colorval)) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
      int m = graph.size();  // Number of nodes
        vector<int> color(m, -1);  // Color array of size m

        for (int i = 0; i < m; i++) {
            if (color[i] == -1) {  // Start DFS if node is uncolored
                if (!BP_DFS(graph, i, color, 1)) return false;
            }
        }
        return true;
    }
};

//Using BFS
//T.S: O(V+E)
class Solution {
public:
    bool BP_BFS(vector<vector<int>>& graph, int val, vector<int>& color) {
        queue<int> q;
        q.push(val);
        color[val]=1;
        while(!q.empty()){
            int val1=q.front();
            q.pop();
            
            for(auto& ngbr: graph[val1]){
                if(color[val1]==color[ngbr]) return false;
                else if(color[ngbr]==-1)
                {
                    q.push(ngbr);
                    color[ngbr]=1-color[val1];
                }
            }
        }        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
      int m = graph.size();  // Number of nodes
        vector<int> color(m, -1);  // Color array of size m

        for (int i = 0; i < m; i++) {
            if (color[i] == -1) {  // Start BFS if node is uncolored
                if (!BP_BFS(graph, i, color)) return false;
            }
        }
        return true;
    }
};

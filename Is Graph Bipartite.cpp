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

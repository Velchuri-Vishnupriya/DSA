
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,src}); //{dis,node}
        int n=adj.size();
        vector<int> res(n,INT_MAX);
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto& vec: adj[node]){
                int v=vec.first;
                int wt=vec.second;
                if(res[v]>d+wt)
{pq.push({d+wt,v});
    res[v]=d+wt;
}            }
        }
    return res;}
};

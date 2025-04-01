//Using set
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        set<pair<int,int>> st;
        st.insert({0,src}); //{dis,node}
        int n=adj.size();
        vector<int> res(n,INT_MAX);
        res[src]=0;
        while(!st.empty()){
            auto& it=*st.begin();
            int d=it.first;
            int node=it.second;
           st.erase(it);
            for(auto& vec: adj[node]){
                int v=vec.first;
                int wt=vec.second;
                if(res[v]>d+wt)
{
  if(res[v]!=INT_MAX){
      st.erase({res[v],v});
   
  }
     st.insert({d+wt,v});
     res[v]=d+wt;
}            }
        }
    return res;}
};

class Solution {
  public:
    // Function to detect cycle in a directed graph.

    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        queue<int> que;
        vector<int> indegree(V,0);
        //step1
        for(int u=0;u<V;u++){
            for(int& v:adj[u]){
                indegree[v]++;
            }
        }
        
        //step2 : fill queue
        int count=0;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                que.push(i);
                count++;
            }
        }
        
        //step-3 Simple BFS
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(int& v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                    count++;
                }
            }
        }
        if(count==V){
            return false;
        }
        else return true;
        
 }
 
};

//Solving Using BFS
//T.C: O(V*(V+E)) BFS is call N times for N- node here N = V;
//S.C: O(V + E) adj list space;

class Solution {
public:
int BFS(int curr, unordered_map<int, vector<int>>& adj, int d, int N ){
    queue<pair<int,int>> que;
    que.push({curr,0});
    vector<bool> visited(N,false);
    visited[curr] = true;

    int count = 0;
    while(!que.empty()){
        int currNode = que.front().first;
        int dist = que.front().second;
        que.pop();

        if(dist > d) continue;

        count ++ ; //include current node in targetnodes count

        //visit the neigbours of currNode
        for(auto& ngbr : adj[currNode] ){
            if(!visited[ngbr]){
                visited[ngbr] = true;
                que.push({ngbr , dist +1});
            }
    }
    }
    return count;
}
vector<int> findCount(vector<vector<int>>& edges, int d){
    int N = edges.size() + 1;

    //adjacency list
    unordered_map<int, vector<int>> adj;
    for(auto& edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> result(N);
    for(int i=0; i<N; i++){
        result[i] = BFS(i, adj, d, N);
    }

    return result;
}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
      int N = edges1.size() + 1 ; //No.of nodes in tree is no.of edges(Given in the question)

      int M = edges1.size() + 1 ;

      vector<int> result1 = findCount(edges1 , k);
      
      vector<int> result2 = findCount(edges2 , k-1);

int maxCount = *max_element(begin(result2),end(result2));

for(int i=0 ; i<result1.size() ; i++){
    result1[i] += maxCount;
}

        return result1 ;}
};

//Using DFS
//T.C: O(V * (V+E)) DFS is called N times for N-nodes
//S.C: O(V + E) adjacency list
class Solution {
public:
//O(V+E)
int DFS(int curr, unordered_map<int, vector<int>>& adj, int d, int curretNodeKaParent ){
    if(d < 0) return 0;

    int count = 1; //counting current node as 1;
    for(int& ngbr: adj[curr] ){
        if(ngbr != currNodeKaParent){
            count += dfs(ngbr, adj, d-1, curr  );
        }
    }

    return count;
}
vector<int> findCount(vector<vector<int>>& edges, int d){
    int N = edges.size() + 1;

    //adjacency list
    unordered_map<int, vector<int>> adj; //O(V+E)
    for(auto& edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> result(N);
    //O(v * (V + E));
    for(int i=0; i<N; i++){
        result[i] = DFS(i, adj, d, -1);
    }

    return result;
}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
      int N = edges1.size() + 1 ; //No.of nodes in tree is no.of edges(Given in the question)

      int M = edges1.size() + 1 ;

      vector<int> result1 = findCount(edges1 , k);
      
      vector<int> result2 = findCount(edges2 , k-1);

int maxCount = *max_element(begin(result2),end(result2)); //O(v)

for(int i=0 ; i<result1.size() ; i++){//O(v)
    result1[i] += maxCount;
}

        return result1 ;}
};

//Using DFS
class Solution {
public:

 vector<int> parent;

        int find(int x){
            if(parent[x]==x) return x;
            return parent[x]=find(parent[x]);
        }

        void Union(int x,int y){
            parent[y]=x;
        }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
       parent.resize(n);
       vector<int> cost(n);
       for(int i=0;i<n;i++){
        parent[i]=i;
        cost[i]=-1;
       }
       for(auto& edge:edges){int u=edge[0];
       int v=edge[1];
       int w=edge[2];
       int parent_u=find(u);
       int parent_v=find(v);
       if(parent_u!=parent_v) {
       Union(parent_u,parent_v);
       cost[parent_u]&=cost[parent_v];
       }
       cost[parent_u]&=w;
       }
       vector<int> result;
       for(auto& q:query){
        int s=q[0];
        int t=q[1];

        int parent_s=find(s);
        int parent_t=find(t);

        if(s==t){
            result.push_back(0);
        }
        else if(parent_s != parent_t){result.push_back(-1);}
       
       else {result.push_back(cost[parent_s]);}
    }
    return result;}
};

//Using BFS
class Solution {
public:
void bfs(int i,unordered_map<int,vector<int>>& adj,vector<bool>& visited,int& v,int& e){
queue<int> q;
q.push(i);
visited[i]=true;

while(!q.empty()){
    int curr=q.front();
    q.pop();
    v++;
    e+=adj[curr].size();

    for(int& ngbr: adj[curr]){
        if(!visited[ngbr]){
            visited[ngbr]=true;
            q.push(ngbr);
        }
    }
}
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
       int res=0;
unordered_map<int,vector<int>> adj;
       for(auto& edge: edges){
        int u=edge[0];
        int v=edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
       }
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(visited[i]==true) continue;
        int v=0;
        int e=0;
        bfs(i,adj,visited,v,e);
        if(v*(v-1)==e){res++;}
    }
    return res; }
};

//Using DSU
class Solution {
public:

class DSU{
    public:
    vector<int> parent;
vector<int> size;
    DSU(int n){
        parent.resize(n);
        size.resize(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
        size[i]=1;
    }
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int x_par=find(x);
        int y_par=find(y);

        if(x_par==y_par) return;
        if(size[x_par]>=size[y_par]){
            parent[y_par]=x_par;
            size[x_par]+=size[y_par];
        }
        else{
 parent[x_par]=y_par;
            size[y_par]+=size[x_par];
        }
    }
};
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
     DSU dsu(n);
     unordered_map<int,int> mp; //root->edges
     for(auto& edge:edges){
        int u=edge[0];
        int v=edge[1];
        dsu.Union(u,v);
     }

     //counting edges for each root
     for(auto& edge: edges){
        int u=edge[0];
        int v=edge[1];
        int root=dsu.find(u); //here dsu.find(u or v) bith is same
        mp[root]++; //increment the edge count
     }
     
     int res=0;
     for(int i=0;i<n;i++){
        if(dsu.find(i)==i){//this is root
int v=dsu.size[i];
int e=mp[i];
if(v*(v-1)==2*e) res++;
        }
       
     }
     return res;  }
};

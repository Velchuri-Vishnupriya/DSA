//T.C: O(ElogV)
//S.c: O(n)
class Solution {
public:
int M=1e9+7;
typedef pair<long long,int> P;
int countPaths(int n,vector<vector<int>>& roads){
//u->({v1,t1},{v2,t2})
unordered_map<int,vector<pair<int,int>>> adj;
for(auto& road:roads ){
    int u=road[0];
    int v=road[1];
    int time=road[2];

    adj[u].push_back({v,time});
    adj[v].push_back({u,time});
}

priority_queue<P,vector<P>,greater<>> pq;
vector<long long> result(n,LLONG_MAX);
vector<int> pathcount(n,0); //to update the NUMBER OF WAYS to reach a node

result[0]=0;
pathcount[0]=1;
pq.push({0,0}); //time ,node

while(!pq.empty()){
    long long currtime=pq.top().first;
    int currnode=pq.top().second;

    pq.pop();

    for(auto& vec: adj[currnode]){
        int ngbr=vec.first;
        int roadtime=vec.second;

        if(currtime+roadtime < result[ngbr]){
            result[ngbr]=currtime+roadtime;
            pq.push({result[ngbr],ngbr});
            pathcount[ngbr]=pathcount[currnode];
        }
        else if(currtime+roadtime==result[ngbr]){
            pathcount[ngbr]=(pathcount[ngbr]+pathcount[currnode])%M;
        }

    }
}
return pathcount[n-1];
}
};

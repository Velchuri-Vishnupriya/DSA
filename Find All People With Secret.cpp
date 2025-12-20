//Approach-1
//T.C : O(M*(M+N)) M-Meetings N-no.of people
//S.C : O(M+N)
class Solution {
public:
typedef pair<int,int> P;

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
map<int, vector<P>> timeMeetings;

for(auto& meet : meetings){
    int P1 = meet[0];
    int P2 = meet[1];
    int time = meet[2];

    timeMeetings[time].push_back({P1,P2});
}

vector<bool> knowsSecret(n,false);
knowsSecret[0] = true;
knowsSecret[firstPerson] = true;

for(auto& it : timeMeetings){
    int time = it.first; //key
    vector<P> meets = it.second; //val

    unordered_map<int,vector<int>> adj; //a -> {b,c,d}
    queue<int> que;
    unordered_set<int> aldreadyAdded;

    for(auto& [p1,p2]: meets){
adj[p1].push_back(p2);
adj[p2].push_back(p1);

if(knowsSecret[p1] == true && aldreadyAdded.find(p1) == aldreadyAdded.end()){
    que.push(p1);
    aldreadyAdded.insert(p1);
}

if(knowsSecret[p2] == true && aldreadyAdded.find(p2) == aldreadyAdded.end()){
    que.push(p2);
    aldreadyAdded.insert(p2);
}
    }

    //Now we know who meets who in increasing order of time
    //Now we need to share the news with others using BFS

    while(!que.empty()){
        int p = que.front();
        que.pop();

        for(auto& nxtp : adj[p]){
            if(knowsSecret[nxtp] == false){
                knowsSecret[nxtp] = true;
                que.push(nxtp);
            }
        }
    }
}

vector<int> result;
for(int i = 0; i < n; i++){
    if(knowsSecret[i]){
        result.push_back(i);
    }
}
    return result;
    }
};

//Approach-2
//T.C : O(M*(M+N)) M-Meetings N-no.of people
//S.C : O(M+N)
class Solution {
public:
typedef pair<int,int> P;

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
unordered_map<int,vector<P>> adj;

for(auto& meet : meetings){//O(M)
    int P1 = meet[0];
    int P2 = meet[1];
    int time = meet[2];

    adj[P1].push_back({P2,time});
    adj[P2].push_back({P1,time});
}

queue<P> que;
que.push({0,0});
que.push({firstPerson,0});

vector<int>timeOfMeet(n,INT_MAX);
timeOfMeet[0] = 0;
timeOfMeet[firstPerson]=0;

while(!que.empty()){//O(M+N)
    auto[P,time] = que.front();
    que.pop();

    for(auto& it: adj[P]){//O(M)
        int nxtPerson = it.first;
        int meetTime = it.second;

        if(meetTime >= time && timeOfMeet[nxtPerson] > meetTime){
            timeOfMeet[nxtPerson] = meetTime;
            que.push({nxtPerson,meetTime});
        }
    }

}

vector<int> result;
for(int i = 0; i < n; i++){
    if(timeOfMeet[i] < INT_MAX){
        result.push_back(i);
    }
}
    return result;
    }
};

//Approach-3 (same as approach 2 but using DFS)
//T.C : O(M*(M+N)) M-Meetings N-no.of people
//S.C : O(M+N)
class Solution {
public:
typedef pair<int,int> P;

void DFS(int person, int time, unordered_map<int, vector<P>>& adj, vector<int>& timeOfMeet){
    for(auto& ngbr : adj[person]){
        int nxtPerson = ngbr.first;
        int meetTime = ngbr.second;

        if(meetTime >= time && timeOfMeet[nxtPerson] > meetTime){
            timeOfMeet[nxtPerson] = meetTime;
            DFS(nxtPerson,meetTime,adj,timeOfMeet);
        }
    }
}
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
unordered_map<int,vector<P>> adj;

for(auto& meet : meetings){//O(M)
    int P1 = meet[0];
    int P2 = meet[1];
    int time = meet[2];

    adj[P1].push_back({P2,time});
    adj[P2].push_back({P1,time});
}

queue<P> que;
que.push({0,0});
que.push({firstPerson,0});

vector<int>timeOfMeet(n,INT_MAX);
timeOfMeet[0] = 0;
timeOfMeet[firstPerson]=0;

DFS(0,0,adj,timeOfMeet);
DFS(firstPerson,0,adj,timeOfMeet);

vector<int> result;
for(int i = 0; i < n; i++){
    if(timeOfMeet[i] < INT_MAX){
        result.push_back(i);
    }
}
    return result;
    }
};

//Approach-4
//T.C : O(M*log N)
//S.C : O(M+N)
class Solution {
public:
typedef pair<int,int> P;

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
unordered_map<int,vector<P>> adj;

for(auto& meet : meetings){//O(M)
    int P1 = meet[0];
    int P2 = meet[1];
    int time = meet[2];

    adj[P1].push_back({P2,time});
    adj[P2].push_back({P1,time});
}

priority_queue<P, vector<P>, greater<>> pq; //{time,Person}
pq.push({0,0});
pq.push({0,firstPerson});

vector<bool>visited(n,false);

while(!pq.empty()){
    auto[time,person] = pq.top();
    pq.pop(); //log(max size of pq)

    if(visited[person] == true){
        continue;
    }

    visited[person] = true;

    for(auto& ngbr: adj[person]){
        int nxtPerson = ngbr.first;
        int meetTime = ngbr.second;

        if(meetTime >= time && !visited[nxtPerson]){
            pq.push({meetTime,nxtPerson});
        }
    }
}

vector<int> result;
for(int i = 0; i < n; i++){
    if(visited[i]){
        result.push_back(i);
    }
}
    return result;
    }
};

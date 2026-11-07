//T.C : O(n * log n + m * log n)
//S.C : O(m)
class Solution {
public:
    typedef pair<int, int> P;//wt, idx
    typedef tuple<long, int, int> T;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
       int n = servers.size();
       int m = tasks.size();

       //free servers (wt, idx)
       priority_queue<P, vector<P>, greater<P>> freeServers;

       //busy servers{finTime, wt, idx}
       priority_queue<T, vector<T>, greater<T>> busyServers;

       for(int i=0; i<n; i++){//n
        freeServers.push({servers[i], i});//O(log n)
       }

       vector<int> result(m);

       for(int i=0; i<m; i++){
        //move busy dervers to free servers if they are free by ith time
        while(!busyServers.empty() && get<0>(busyServers.top()) <= i){
            auto [finTime, wt, idx]=busyServers.top();
            busyServers.pop();
            freeServers.push({wt, idx});
        }

        if(freeServers.empty()){
            auto[finTime, wt, idx] = busyServers.top();
            busyServers.pop();
            result[i] = idx;
            busyServers.push({finTime + tasks[i], wt, idx});
        }else{
            auto[wt, idx] = freeServers.top();
            freeServers.pop();
            result[i] = idx;
            busyServers.push({i+tasks[i], wt, idx});
        }
       }
   return result;
    }
};

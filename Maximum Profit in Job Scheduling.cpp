//Recurssion + Memoization
//T.C : O(n* log n)
//S.C : O(n)
class Solution {
public:
int n;
vector<int> t;
    int solve(vector<vector<int>>& events, int i){
        if(i>=n) return 0;

        if(t[i] != -1) return t[i];

        //skip
        int skip = solve(events,i+1);

        //take
        int end = events[i][1];
        int j = i+1;
        vector<int> temp = {end,0,0};
        j = lower_bound(events.begin(),events.end(),temp) - events.begin(); 
        int take = events[i][2] + solve(events, j);

        return t[i] = max(skip,take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> events;
        
        n = startTime.size();
        
        for(int i=0; i<n; i++){
            events.push_back({startTime[i],endTime[i],profit[i]});
        }

        sort(begin(events),end(events));

        t.resize(n,-1);

        return solve(events,0);
    }
};

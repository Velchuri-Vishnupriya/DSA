//Using Linear Search
//T.C : O((n+1)*(k+1)*n) ~ O(n^2)
class Solution {
public:
int n;
vector<vector<int>> t;
    int solve(vector<vector<int>>& events, int idx, int k){
if(idx >= n || k==0) return 0;

if(t[idx][k] != -1) return t[idx][k];

int start = events[idx][0];
int end = events[idx][1];
int value = events[idx][2];

//skip
int skip = solve(events, idx+1,k);

//take --> Linear Search
int j = idx+1;
for(; j < n; j++){
    if(events[j][0] > events[idx][1]) break;
}
int take = value + solve(events,j,k-1);
return t[idx][k] = max(skip,take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events),end(events));

        n = events.size();

t.resize(n+1, vector<int>(k+1 , -1));

        return solve(events,0,k);
    }
};

//Using Binary Search
//T.C : O((n+1)*(k+1)*log n) ~ O(n*k*logn)
class Solution {
public:
int n;
vector<vector<int>> t;
    int solve(vector<vector<int>>& events, int idx, int k){
if(idx >= n || k==0) return 0;

if(t[idx][k] != -1) return t[idx][k];

int start = events[idx][0];
int end = events[idx][1];
int value = events[idx][2];

//skip
int skip = solve(events, idx+1,k);

//take --> Binary Search
vector<int> temp = {end,INT_MAX,INT_MAX};
int j = upper_bound(events.begin(),events.end(),temp)-events.begin();
int take = value + solve(events,j,k-1);
return t[idx][k] = max(skip,take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events),end(events));

        n = events.size();

t.resize(n+1, vector<int>(k+1 , -1));

        return solve(events,0,k);
    }
};

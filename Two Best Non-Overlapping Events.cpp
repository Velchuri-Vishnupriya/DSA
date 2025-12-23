//Recursion + Memoization
//T.C : O(n*log n)
//S.C : O(1)
class Solution {
public:
int n;
//t[idx][count]
int t[100001][3];
//cutstomized upper_bound
int binarySearch(vector<vector<int>>& events, int endTime){
int l = 0; 
int r = n-1;
int res = n;

while(l <= r){
    int mid = l + (r-l)/2;

    if(events[mid][0] > endTime){
        res = mid;
        r = mid -1;
    }else{
        l = mid + 1;
    }
}

return res;
}
int solve(vector<vector<int>>& events, int i, int count){
    if(i >= n || count == 2)return 0;
    if(t[i][count] != -1) return t[i][count];

    int nextValidEventIndex = binarySearch(events, events[i][1]);//O(log n)
    int take = events[i][2] + solve(events, nextValidEventIndex, count+1);

    int not_take = solve(events, i+1, count);

    return t[i][count] = max(take, not_take);
 
}
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end());//O(nlogn)
        memset(t,-1,sizeof(t));
        int count = 0;
        return solve(events, 0, count);
    }
};

//Bottom - Up
class Solution {
public:
int n;
//cutstomized upper_bound
int binarySearch(vector<vector<int>>& events, int endTime){
int l = 0; 
int r = n-1;
int res = n;

while(l <= r){
    int mid = l + (r-l)/2;

    if(events[mid][0] > endTime){
        res = mid;
        r = mid -1;
    }else{
        l = mid + 1;
    }
}

return res;
}
int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end());
        int t[n+1][3];
        t[n][0] = 0;
        t[n][1] = 0;
        for(int i = 0; i <= n; i++){
            t[i][2] = 0;
        }
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                int nextValidIndex = binarySearch(events, events[i][1]);
                int take = events[i][2] + t[nextValidIndex][j+1];
                int not_take = t[i+1][j];
                t[i][j] = max(take,not_take);
            }
        }
   return t[0][0];
    }
};

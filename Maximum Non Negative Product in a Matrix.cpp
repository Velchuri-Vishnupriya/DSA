//Recursion + Memoization
//T.C : O(m*n)
//S.C : O(m*n)
class Solution{
public:
int m, n;
typedef long long ll;
int MOD = 1e9 + 7;
vector<vector<pair<ll,ll>>> t;
pair<ll,ll>solve(int i, int j, vector<vector<int>>& grid){
    if(i == m-1 && j == n-1)
    { return {grid[i][j], grid[i][j]}; }
    
        if(t[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) return t[i][j];

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        //down
        if(i+1 < m){
        auto [downMax, downMin] = solve(i+1, j, grid);
        maxVal = max({maxVal, grid[i][j]*downMax, grid[i][j]*downMin});
  minVal = min({minVal, grid[i][j]*downMax, grid[i][j]*downMin});
        }

        //right
        if(j+1 < n){
            auto [rightMax, rightMin] = solve(i, j+1, grid);
        maxVal = max({maxVal, grid[i][j]*rightMax, grid[i][j]*rightMin});
  minVal = min({minVal, grid[i][j]*rightMax, grid[i][j]*rightMin});
        }
    
     return t[i][j] = {maxVal, minVal};
}
int maxProductPath(vector<vector<int>>& grid){   
    m = grid.size();
    n = grid[0].size();
    t.assign(m, vector<pair<ll,ll>>(n, {LLONG_MIN, LLONG_MAX}));
    auto [maxPdt, minPdt] = solve(0,0,grid);
return (maxPdt >= 0) ? maxPdt % MOD : -1;
}
};

//Bottom - Up
//Maximum Non Negative Product in a Matrix
//T.C : O(m*n)
//S.C : O(m*n)
class Solution{
public:
int m, n;
typedef long long ll;
int MOD = 1e9 + 7;
vector<vector<pair<ll,ll>>> t;
int maxProductPath(vector<vector<int>>& grid){   
    m = grid.size();
    n = grid[0].size();
    t.assign(m, vector<pair<ll,ll>>(n, {LLONG_MIN, LLONG_MAX}));
    t[0][0] = {grid[0][0], grid[0][0]};

    //fill row 1
    for(int j = 1; j < n; j++){
        t[0][j] = {t[0][j-1].first*(ll)grid[0][j], t[0][j-1].second*(ll)grid[0][j]};
    }

    //fill col1 1
    for(int i = 1; i < m; i++){
        t[i][0] = {t[i-1][0].first*grid[i][0], t[i-1][0].second*grid[i][0]};
    }

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            ll upperMax = max(t[i-1][j].first, t[i-1][j].second);
            ll upperMin = min(t[i-1][j].first, t[i-1][j].second);
            ll leftMax = max(t[i][j-1].first, t[i][j-1].second);
            ll leftMin = min(t[i][j-1].first, t[i][j-1].second);
            ll val = (ll)grid[i][j];
            t[i][j] = {max({upperMax*val, upperMin*val, leftMax*val, leftMin*val}),
            min({upperMax*val, upperMin*val, leftMax*val, leftMin*val})};
        }
    }
    ll maxPdt = t[m-1][n-1].first;
return (maxPdt >= 0) ? maxPdt % MOD : -1;
}
};

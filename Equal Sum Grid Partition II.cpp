//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
typedef long long ll;
ll total = 0;

bool checkHorCuts(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();

    unordered_set<ll> st;
    ll top = 0;
    for(int i=0; i<m-1; i++){
        for(int j=0; j<n ; j++){
            top += (ll)grid[i][j];
            st.insert(grid[i][j]);
        }
ll bottom = total - top;
ll diff = (top - bottom);
if(diff == 0)return true;
if(diff == (ll)grid[0][0])return true;
if(diff == (ll)grid[0][n-1])return true;
if(diff == (ll)grid[i][0])return true;

if(i > 0 && n > 1 && st.count(diff))return true;
    }
    return false;
}
    bool canPartitionGrid(vector<vector<int>>& grid) {
     int m = grid.size();
     int n = grid[0].size();

     for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            total += grid[i][j];
        }
     }
     if(checkHorCuts(grid)){
        return true;
     }

     reverse(begin(grid), end(grid));

     if(checkHorCuts(grid)){
        return true;
     }

     reverse(begin(grid), end(grid));

     //Now column cut
     //Transpose
     vector<vector<int>> transposeGrid(n, vector<int>(m,n));

     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            transposeGrid[i][j] = grid[j][i];
        }
     }

     if(checkHorCuts(transposeGrid)){
        return true;
     }

     reverse(begin(transposeGrid), end(transposeGrid));

     if(checkHorCuts(transposeGrid)){
        return true;
     }

     return false;
    }
};

//T.C : O(n*m)
//S.C : O(n*m)
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        //typedef long long ll;
        int M = 12345;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>p(n,vector<int>(m,0));

        long long suffix = 1;
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                p[i][j] = suffix;
                suffix = (suffix*grid[i][j]) % M;
            }
        }

        long long prefix = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                p[i][j] = (p[i][j] * prefix) % M;
                prefix = (prefix * grid[i][j]) % M;
            }
        }
    return p;}
};

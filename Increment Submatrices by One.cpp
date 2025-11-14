//Brute Force
//T.C : O(n^2 * q)
//S.C : O(1)
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        for(auto& query: queries){
            int row1=query[0];
            int row2=query[2];
            int col1=query[1];
            int col2=query[3];
            for(int x=row1; x<=row2; x++){
                for(int y=col1; y<=col2; y++){
                    if(x<n && y<n){
                        grid[x][y]+=1;
                    }
                }
            }
        }
    return grid;}
};

//Difference Array Technique
//T.C : O(q*n + n*n)
//S.C : O(1)
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
   vector<vector<int>> diff(n,vector<int>(n,0));
   for(auto& query: queries){
    int r1 = query[0];
    int c1 = query[1];
    int r2 = query[2];
    int c2 = query[3];
    for(int i=r1; i<=r2; i++){
        diff[i][c1] += 1;
        if(c2 + 1 < n) diff[i][c2 + 1] -= 1;
    }
   }
   //cum sum
   for(int i = 0; i < n; i++){
    for(int j = 1; j < n; j++){
        diff[i][j] += diff[i][j-1];
    }
   }
   return diff;}
};

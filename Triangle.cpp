//Approach -1 Recurrsion + memoization 
//T.C: O(n^2)
//S.C: O(n^2)
class Solution {
public:
int n;
int t[201][201];
int solve(vector<vector<int>>& triangle, int row, int col){
    if(row == n - 1) return triangle[row][col];
    if(t[row][col] != -1){
        return t[row][col];
    }
    int minSum = triangle[row][col] + min(solve(triangle, row + 1, col), solve(triangle, row + 1, col + 1));

    return t[row][col] = minSum;
}
    int minimumTotal(vector<vector<int>>& triangle) {
      n = triangle.size();
      memset(t, -1, sizeof(t));
      return solve(triangle, 0, 0);
    }
};

//Approach -1  Bottom - Up
//T.C: O(n^2)
//S.C: O(n^2)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      int n = triangle.size();
      vector<vector<int>> t = triangle; //space = O(n^@)
      //t[i][j] = minpath sum from [i][j] to bottom

      for(int row = n-2; row>=0; row--){
        for(int col=0; col<=row; col++){
            t[row][col] = t[row][col] + min(t[row+1][col], t[row+1][col+1]);
        }
      }
   return t[0][0];
    }
};

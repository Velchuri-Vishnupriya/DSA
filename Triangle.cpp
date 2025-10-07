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

//Approach -2  Bottom - Up
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

//Approach -3  Bottom - Up - optimized
//T.C: O(n^2)
//S.C: O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      int n = triangle.size();
      vector<int> t = triangle[n-1]; //space = O(n)

      for(int row = n-2; row>=0; row--){
        for(int col=0; col<=row; col++){
            t[col] = triangle[row][col] + min(t[col], t[col+1]);
        }
      }
   return t[0];
    }
};

//Approach -4  Bottom - Up - optimized
//T.C: O(n^2)
//S.C: O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      int n = triangle.size();
     
      for(int row = 1; row < n; row++){
        for(int col=0; col <= row; col++){
            triangle[row][col] = triangle[row][col] + 
            min(
                triangle[row-1][max(col-1,0)], 
                triangle[row-1][min(col,row-1)]
                );
        }
      }
   return *min_element(triangle[n-1].begin(), triangle[n-1].end());
    }
};

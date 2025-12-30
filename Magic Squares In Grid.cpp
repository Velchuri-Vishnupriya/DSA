//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
int m , n;
bool isMagicGrid(vector<vector<int>>& grid, int r, int c){
   //uniqueness
   unordered_set<int> st;
   for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
        int num = grid[r + i][c + j];
        if(num > 9 || num < 1 || st.count(num)){
            return false;
        }else{
            st.insert(num);
        }
    }
   }

   //row sum and col sum
   int rSum = grid[r][c] + grid[r][c+1] + grid[r][c+2];

   for(int i = 0; i < 3; i++){
    if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != rSum) return false;
    if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != rSum) return false;
   }

   //diagonal and anti-diagonal sum
   int dSum = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
   if(dSum != rSum) return false;
   int antiDSum = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];
   if(antiDSum != rSum) return false;
    return true;
}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
    //cols = grid[0].size()-3
    //rows = grid.size()-3
    m = grid.size();
    n = grid[0].size();
    int count  = 0;
    if(m < 3) return false;

    for(int i = 0; i <= grid.size() - 3; i++){//O(m-3)
        for(int j = 0; j <= grid[0].size() - 3; j++){//O(n-3)
            if(isMagicGrid(grid,i,j)) count++;//(3*3)
        }
    }

   return count;
    }
};

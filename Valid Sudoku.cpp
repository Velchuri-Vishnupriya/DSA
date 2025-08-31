//Approach - 1 -Brute Force
//T.C : O(9*9)~O(1)
//S.C : O(9)~O(1)
class Solution {
public:
bool traverse(vector<vector<char>>& grid, int sr, int er, int sc, int ec){
    set<int> st;
    for(int i = sr; i <= er; i++){
        for(int j = sc; j <= ec; j++){
            if(grid[i][j] == '.') continue;    
            if(st.find(grid[i][j])!=st.end()) return false;
            else st.insert(grid[i][j]);
        }
    }
    return true;
}
    bool isValidSudoku(vector<vector<char>>& grid) {
  int m = grid.size();
  int n = grid[0].size();
  set<int> st;
   //rows check
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
        if(grid[i][j] == '.') continue;
        if(st.find(grid[i][j]) != st.end()) return false;
        else st.insert(grid[i][j]);
    }
    st.clear();
  }
   //cols check
     for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
        if(grid[j][i] == '.') continue;
        if(st.find(grid[j][i]) != st.end()) return false;
        else st.insert(grid[j][i]);
    }
     st.clear();
  }

  //3 x 3 box check
for(int sr = 0; sr < m; sr+=3){
    int er = sr + 2;
    for(int sc = 0; sc < n; sc+=3){
        int ec = sc + 2;
        if(traverse(grid,sr,er,sc,ec) == false) return false;
    }
}
  return true;  }
};

//Approach - 2 
//T.C : O(9*9)~O(1)
//S.C : O(243)~O(1) - 3 entries for each cell 3*81 = 243
class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& grid) {
  int m = grid.size();
  int n = grid[0].size();
  unordered_set<string> st;
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
        if(grid[i][j] == '.') continue;
        int i_ = i/3;
        int j_ = j/3;
        string row = to_string(grid[i][j]) + "found at row" + to_string(i);
        string col = to_string(grid[i][j]) + "found at col" + to_string(j);
        string box = to_string(grid[i][j]) + "found at " + to_string(i_) + "_" + to_string(j_);
        if(st.find(row) != st.end() || st.find(col) != st.end() || st.find(box) != st.end()) return false;
        else{
            st.insert(row);
            st.insert(col);
            st.insert(box);
        }
        
    }
      }

  return true;  }
};

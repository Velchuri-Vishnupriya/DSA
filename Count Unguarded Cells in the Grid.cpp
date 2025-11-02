//T.C : O(size(gaurds) * (m + n))
//S.C : O(m*n)
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
vector<vector<int>> grid(m, vector<int>(n,0));

//0 = empty 1 = gaurd 2 =wall 3 = gaurded

for(auto& g: guards){//O(G)
    grid[g[0]][g[1]] = 1;
}

for(auto& w: walls){//O(W)
    grid[w[0]][w[1]] = 2;
}

vector<vector<int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};

for(auto& g : guards){//O(G)
    for(auto& dir : directions){
        int i_ = g[0] + dir[0];
        int j_ = g[1] + dir[1];

        while(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n){//O(m+n)
            if(grid[i_][j_] == 1 || grid[i_][j_] == 2) break;
            if(grid[i_][j_] == 0) grid[i_][j_] = 3;
            i_ += dir[0];
            j_ += dir[1];
        }
    }
}

int count = 0;
for(int row = 0; row < m; row++){
    for(int col = 0; col < n; col++){
        (grid[row][col] == 0) ? count+=1 : count+=0;
    }
}
    return count;}
};

//Using DFS
class Solution {
public:
int m,n;
int dfs(int i,int j,vector<vector<int>>& grid){
    int fishcnt=grid[i][j];
    grid[i][j]=0;
    for(vector<int>&dir :directions){
        int i_=i+dir[0];
        int j_=j+dir[1];
        if(i_>=0 && i_<m && j_<n && j_>=0){
            if(grid[i_][j_]>0){
                fishcnt+=grid[i_][j_];
                grid[i_][j_]=0;
                fishcnt+=dfs(i_,j_,grid);
            }
        }
    }
    return fishcnt;
}
vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
    int findMaxFish(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int maxfish=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    maxfish=max(maxfish,dfs(i,j,grid));
                }
            }
        }
   return maxfish; }
};

//Using BFS
class Solution {
public:
int m,n;
vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
int bfs(int i,int j,vector<vector<int>>& grid){
  queue<pair<int,int>> q;
  q.push({i,j});
   int fishcnt=grid[i][j];
    grid[i][j]=0;
    while(!q.empty()){
        i=q.front().first;
        j=q.front().second;
        q.pop();
        for(auto& dir:directions){
            int i_=dir[0]+i;
            int j_=dir[1]+j;
            if(i_>=0 && i_<m && j_>=0 && j_<n && grid[i_][j_]>0){
                fishcnt+=grid[i_][j_];
                q.push({i_,j_});
                grid[i_][j_]=0;
            }
        }
    }
    return fishcnt;
}

    int findMaxFish(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int maxfish=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    maxfish=max(maxfish,bfs(i,j,grid));
                }
            }
        }
   return maxfish; }
};


//Using DSU
// T.C : O(m*n * alpha(m*n))
// S.C : O(m*n)


class DSU {
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void unionSets(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) return;

        if (size[y_parent] < size[x_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        } else {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }

    void setSize(int x, int fishCount) {
        size[x] = fishCount;
    }

    int maxElement() {
        return *max_element(begin(size), end(size));
    }
};

class Solution {
public:
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int totalCells = m * n;
        DSU dsu(totalCells);

        // Initialize DSU sizes with fish counts
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    int idx = i * n + j;
                    dsu.setSize(idx, grid[i][j]);
                }
            }
        }

        // Union adjacent fish-containing cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    int idx = i * n + j;
                    for (auto& dir : directions) {
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];

                        if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0) {
                            int idx_ = i_ * n + j_;
                            dsu.unionSets(idx, idx_);
                        }
                    }
                }
            }
        }

        return dsu.maxElement();
    }
};

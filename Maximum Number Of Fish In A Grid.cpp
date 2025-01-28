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

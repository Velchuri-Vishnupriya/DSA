//Using DFS
class Solution {
public:
int m;int n;
vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(int i,int j,vector<vector<char>>& grid){
    grid[i][j]='0';
for(auto& dir:directions){
    int i_=dir[0]+i;
    int j_=dir[1]+j;
if(i_>=0 && i_<m && j_>=0 && j_<n){
    if(grid[i_][j_]=='1'){
        dfs(i_,j_,grid);
    }
}
}
}
    int numIslands(vector<vector<char>>& grid) {
        //vector<vector<bool>> visited(m,vector(n,false));
        m=grid.size();
    n=grid[0].size();
    int islandcnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
islandcnt+=1;
dfs(i,j,grid);}
        }
    }
        
   return islandcnt; }
};

//Using BFS
class Solution {
public:
int m;int n;
vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
void bfs(int i,int j,vector<vector<char>>& grid){
    grid[i][j]=0;
    queue<pair<int,int>> q;
    q.push({i,j});
    while(!q.empty()){
         i=q.front().first;
        j=q.front().second;
        q.pop();
        for(auto& dir:directions){
            int i_=dir[0]+i;
            int j_=dir[1]+j;
            if(i_>=0 && i_<m && j_>=0 && j_<n && grid[i_][j_]=='1'){
                q.push({i_,j_});
                grid[i_][j_]='0';
            }
        }
    }
}

    int numIslands(vector<vector<char>>& grid) {
        //vector<vector<bool>> visited(m,vector(n,false));
        m=grid.size();
    n=grid[0].size();
    int islandcnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
islandcnt+=1;
bfs(i,j,grid);}
        }
    }
        
   return islandcnt; }
};

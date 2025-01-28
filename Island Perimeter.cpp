//Using DFS
class Solution {
public:
int row;
int col;
vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
int dfs(int i,int j,vector<vector<int>>& grid){
    int cnt=0;
    grid[i][j]=-1;
    for(auto& dir:directions){
        int i_=dir[0]+i;
        int j_=dir[1]+j;
        if(j_<0 || j_>col-1 ) cnt++;
       else if( i_<0|| i_>row-1) cnt++;
       else if(grid[i_][j_]==0) cnt++; 
    else if(grid[i_][j_]==1) cnt+=dfs(i_,j_,grid);
        }
    
    return cnt;
}
    int islandPerimeter(vector<vector<int>>& grid) {
      row=grid.size();
      col=grid[0].size();  
      int perimeter=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==1){
               perimeter+= dfs(i,j,grid);
            }
        }
    }
    return perimeter;
    }
};

//Using BFS
class Solution {
public:
int row;
int col;
vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
int bfs(int i,int j,vector<vector<int>>& grid){
    int cnt=0;
    queue<pair<int,int>> q;
    q.push({i,j});
      grid[i][j]= -1;
    while(!q.empty()){
         i=q.front().first;
        j=q.front().second;
      
        q.pop();
        for(auto& dir:directions){
            int i_=dir[0]+i;
            int j_=dir[1]+j;
              if(i_>=row || i_<0 || j_>=col || j_<0)cnt++; 
               else if(grid[i_][j_]==0)cnt++;
               else if(grid[i_][j_]==1) {q.push({i_,j_});
               grid[i_][j_]= -1;}     
    }
    }
    return cnt;
}
    int islandPerimeter(vector<vector<int>>& grid) {
      row=grid.size();
      col=grid[0].size();  
      int perimeter=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==1){
               perimeter+= bfs(i,j,grid);
            }
        }
    }
    return perimeter;
    }
};

//Taversing 2D matrix
class Solution {
public:
int row;
int col;
vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
    int islandPerimeter(vector<vector<int>>& grid) {
      row=grid.size();
      col=grid[0].size();  
      int perimeter=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==1) {
                grid[i][j] = -1;
for(auto& dir: directions){
    int i_=dir[0]+i;
    int j_=dir[1]+j;
    if(i_<0 || i_>=row) perimeter++;
  else if(j_<0 || j_>=col ) perimeter++;
    else if (grid[i_][j_]==0) perimeter++; 
}

            }
        }
    }
    return perimeter;
    }
};

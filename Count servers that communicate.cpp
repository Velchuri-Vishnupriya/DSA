//Approach-1
T.S : (M*n);
S.C: (M+n);
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<int> colcount(n,0);
        vector<int> rowcount(m,0);
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1){
                 colcount[col]++;
                 rowcount[row]++;  
                }
            }
        } 
        int result=0;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1 && (colcount[col]>1 || rowcount[row]>1))
{result+=1;}            }
        }
    return result;}
};

//Approach-2
//T.S: O(m*n +n) 
//S.C: O(m+n)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

vector<int> colservercount(n,0);
vector<int> rowaloneservercol(m,-1);
int result=0;
for(int row=0;row<m;row++){
    int countserverrow=0;
    for(int col=0;col<n;col++){
if(grid[row][col]==1){
    countserverrow+=1;
    colservercount[col]++;
    rowaloneservercol[row]=col;
}

    }
    if(countserverrow>1){
        result+=countserverrow;
        rowaloneservercol[row]=-1;
    }
}    
for(int row=0;row<m;row++){
     if(rowaloneservercol[row]!=-1){
        int col=rowaloneservercol[row];
        if(colservercount[col]>1){
            result+=1;
        }
     }
}    
    return result;}
}

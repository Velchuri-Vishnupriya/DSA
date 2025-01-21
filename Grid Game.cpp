//T.S : O(grid.size())
//S.C: 1
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
      long long firstRowRemainSum=accumulate(
        begin(grid[0]),end(grid[0]),0LL);

        long long secondRowRemainSum=0;
        long long mini=LONG_LONG_MAX;
        for(int robo1=0;robo1<grid[0].size();robo1++){
            firstRowRemainSum-=grid[0][robo1];
            long long best=max(firstRowRemainSum,secondRowRemainSum);
                 mini=min(mini,best); 
                 secondRowRemainSum+=grid[1][robo1];  }
                 return mini;
    
    }
};

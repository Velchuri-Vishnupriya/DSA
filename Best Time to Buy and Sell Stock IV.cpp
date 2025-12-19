//Recurrsion + Memoization
//T.C : O(n)
//T.C : O(n)
class Solution {
public:
int n;
int k1;
int t[1001][2][101];
int solve(int i,int buy, int k, vector<int>& prices){
if(i >= n || k == k1) return 0;
if(t[i][buy][k] != -1) return t[i][buy][k];
int profit = 0;
if(buy == 1){
    //buy not buy
    profit = max(0 + solve(i+1,1,k,prices),
    -prices[i] + solve(i+1,0,k,prices));
}else{
    //sell not sell
    profit = max(0 + solve(i+1,0,k,prices),
    prices[i]+solve(i+1,1,k+1,prices));
}

return t[i][buy][k] = profit;
}
    int maxProfit(int K, vector<int>& prices) {
        n = prices.size();
        k1 = K;
        memset(t,-1,sizeof(t));
        return solve(0,1,0,prices); //idx,buy,k,prices
    }
};

//Bottom - Up
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        int t[n+1][2][k+1];

        for(int i =0; i<2; i++){
            for(int j=0; j<k+1; j++){
                t[n][i][j] = 0;
            }
        }

        for(int i = 0; i < n+1; i++){
            for(int j =0; j < 2; j++){
                t[i][j][k] = 0;
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy < 2; buy++){
                for(int K=0; K < k; K++){
                    //buy == 1
                    if(buy == 1){
                        //buy or not buy
                        t[i][1][K] = 0 + t[i+1][1][K]; //not buy
                        t[i][1][K] = max(t[i][1][K], 
                        -prices[i] + t[i+1][0][K]); 
                   }else{
                    //sell not sell
                    t[i][0][K] = t[i+1][0][K];
                    t[i][0][K] = max(t[i][0][K], 
                    prices[i] + t[i+1][1][K+1]);
                   }
                }
            }
        }
        
  return t[0][1][0];
    }
};

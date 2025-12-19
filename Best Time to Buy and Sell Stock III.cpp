//Approach -1 Recurrsion + Memoization
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
int t[100001][2][2];
int n;
int solve(int i, int buy, int k, vector<int>& prices){
    if(i >= n || k == 2) return 0;

    if(t[i][buy][k] != -1) return t[i][buy][k];
    int profit = 0;
    if(k < 2){
        if(buy == 1){
            //take not take
            profit= max(0 + solve(i+1,1,k,prices),
                        -prices[i] + solve(i+1,0,k,prices));
        }

        if(buy == 0){
            //sell not sell
            profit = max(0 + solve(i+1,0,k,prices),
                         prices[i] + solve(i+1,1,k+1,prices));
        }
    }

    return t[i][buy][k] = profit;
}
    int maxProfit(vector<int>& prices) {
        //we introduce new variable k
        n = prices.size();
        for(int i = 0; i < 100001; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    t[i][j][k] = -1;
                }
            }
        }
        return solve(0,1,0,prices);  //idx,buy,k
    }
};

//Bottom - Up
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //we introduce new variable k
       int n = prices.size();
       int k = 2;

       int t[n+1][2][3];

       t[n][0][0] = 0;
       t[n][0][1] = 0;
       t[n][1][0] = 0;
       t[n][1][1]= 0;
       
       for(int i =0 ;i < n+1; i++){
        t[i][0][2] = 0;
        t[i][1][2] = 0;
       }
       
       for(int i = n-1; i >= 0; i--){
        for(int buy = 0; buy < 2; buy++){
            for(int k = 0; k < 2; k++){
                //buy == 1
                if(buy == 1){
                    //not take
                    t[i][1][k] = 0 + t[i+1][1][k];
                    //take
                    t[i][1][k] = max(t[i][1][k],
                                     -prices[i] + t[i][0][k]);
                }
                else{
                    //not sell
                    t[i][0][k] = 0 + t[i+1][0][k];
                    //sell
                    t[i][0][k] = max(t[i][0][k],
                                     prices[i] + t[i+1][1][k+1]);
                }
            }
        }
       }
    return t[0][1][0];
    }
};

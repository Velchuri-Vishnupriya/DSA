//Approach - 1: Recurrsion + Memoization
//T.C : O(n*k)
//S.C : O(n*k)
class Solution {
public:
int n;
long long t[1001][501][3];

//CASES
//0 -> Not bought anything and not short sold anything.
//1 -> Normal Transaction: Bought the stock normally and have to sell.
//2 -> Short selling Transaction: Sold the short selling stock need to buy

long long solve(int i, int k, int CASE, vector<int>& prices){
    if(i >= n){
        if(CASE == 0) return 0;
        return INT_MIN;
    }

    if(t[i][k][CASE] != INT_MIN) return t[i][k][CASE];

    long long take = INT_MIN;
    long long dontTake;

    //dontTake - do nothing just skip to nxt transaction
    dontTake = solve(i+1, k, CASE, prices);

    //Take Action
    if(k > 0){
        if(CASE == 1){
            //sell 2day 
            take = prices[i] + solve(i+1, k-1, 0, prices);
        }else if(CASE == 2){
            //Buyback 2day
            take = -prices[i] + solve(i+1, k-1, 0, prices);
        }else{
            //CASE == 0: Start new transaction
            take = max(-prices[i] + solve(i+1, k, 1, prices),
            prices[i] + solve(i+1, k, 2, prices));
        }
    }

    return t[i][k][CASE] = max(take,dontTake);
}    
long long maximumProfit(vector<int>& prices, int k) {
       n = prices.size();

       for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            for(int l = 0; l < 3; l++){
                t[i][j][l] = INT_MIN;;
            }
        }
       }

    return solve(0,k,0,prices);
    }
};

//Approach - 2: Bottom Up
//T.C : O(n*k)
//S.C : O(n*k)
class Solution {
public:
int n;
long long t[1001][501][3];
long long maximumProfit(vector<int>& prices, int K) {
       n = prices.size();

for(int k = 0; k <= K; k++){
    t[n][k][0] = 0;
    t[n][k][1] = t[n][k][2] = INT_MIN;
}

for(int i = n-1; i >= 0; i--){
    for(int k = 0; k <= K; k++){

        t[i][k][0] = t[i+1][k][0];//Don't take

        if(k > 0){
            //case 0
            t[i][k][0] = max(max(-prices[i] + t[i+1][k][1],
            prices[i] + t[i+1][k][2]), t[i][k][0]);

            //case 1
            t[i][k][1] = t[i+1][k][1];
            t[i][k][1] = max(max(t[i][k][1], prices[i] + t[i+1][k-1][0]), t[i][k][1]);

            //case 2
            t[i][k][2] = t[i+1][k][2];
            t[i][k][2] = max(max(t[i][k][2], -prices[i] + t[i+1][k-1][0]), t[i][k][2]);
        }
    }
}
   return t[0][K][0];
    }
};

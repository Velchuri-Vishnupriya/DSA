//Approach - 1 Recurrsion + Memoization
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
int t[30001][2];
int n;
int solve(int i, int buy, vector<int>&prices){
    if(i >= n) return 0;

    if(t[i][buy] != -1) return t[i][buy];
    
int profit  = 0;

//if there is option to buy
if(buy == 1){
profit = max(-prices[i] + solve(i+1, 0, prices),// you buy
            0 + solve(i+1, 1, prices) //skip buying 
            );
}

else{
    profit = max(prices[i] + solve(i+1, 1, prices), //u sell it
                  0 + solve(i+1, 0, prices)//u don't sell it
                  );
}
return t[i][buy] = profit;
}
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(t, -1, sizeof(t));
        return solve(0, 1, prices);
    }
};

//Bottom - up
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       int t[n+1][2];
       //buy = 0 or 1 when i=n it shd be zero
       t[n][0] = 0;
       t[n][1] = 0;

       for(int i = n-1; i >= 0; i--){
        for(int buy = 0; buy < 2; buy++){
if(buy == 1){
    //don't buy
    t[i][buy] = 0 + t[i+1][buy];
    //buy
    t[i][buy] = max(t[i][buy],
                     -prices[i] + t[i+1][0]);
}

if(buy == 0){
    //don't sell
    t[i][buy] = 0 + t[i+1][buy];
    //sell
    t[i][buy] = max(t[i][buy],
                    prices[i] + t[i+1][1]);
}
        }
       }
       return t[0][1];
    }
};

//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
       long long len = 1;
       int n = prices.size();
       long long res = 0;
       for(int i = 1; i<n; i++){
        if(prices[i] - prices[i-1] == -1){
            len++;
        }else{
res += ((len * (len+1))/2);
len = 1;
        }
       }
       res += ((len*(len+1))/2);
    return res;
    }
};

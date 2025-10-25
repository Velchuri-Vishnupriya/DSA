//T.C : O(Q*7 + rem)) = O(n)
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) {
        vector<int>vec {1,2,3,4,5,6,7};
        int sum = 0;
        int Q = n / 7;
        while(Q){
            for(int i = 0; i < 7; i++){
                sum = sum + (Q - 1) + vec[i];
            }
            Q--;
        }
        int rem = n % 7;
        int newQ = (n/7) + 1;
        for(int i =0; i < rem; i++){
            sum = sum + (newQ - 1) + vec[i];
        }
        return sum;
    }
};

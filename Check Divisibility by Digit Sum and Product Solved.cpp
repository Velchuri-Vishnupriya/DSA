//T.C : O(log(N)+1)
//S.C : O(1)
class Solution {
public:
    bool checkDivisibility(int N) {
        int digitSum =0;
        int digitPrdt =1;
        int n = N;
        while(n){
            int d = n%10;
            n/=10;
            digitSum += d;
            digitPrdt *= d;
        }
        return N%(digitSum+digitPrdt)==0;
    }
};

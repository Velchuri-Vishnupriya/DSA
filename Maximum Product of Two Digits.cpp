//T.C : O(d) d=no.of digits in N
//S.C : O(d)
class Solution {
public:
    int maxProduct(int n) {
       vector<int> digits;
       while(n){
        digits.push_back(n%10);
        n/=10;
       } 
       sort(digits.begin(), digits.end(),[](int& a, int& b){return a>b;}
       );
       return digits[0]*digits[1];
    }
};

//T.C : O(log n) each operation reduces n at least by a factor of 2 so log n base 2
//S.C: O(1)
class Solution {
public:

    bool isUgly(int n) {
 if(n<=0) return false;
 while(n%2 == 0) n/=2;
 while(n%3 == 0 ) n/=3;
 while(n%5 == 0) n/=5;
 return n==1;
    }
};

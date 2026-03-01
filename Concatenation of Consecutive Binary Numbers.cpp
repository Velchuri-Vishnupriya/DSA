//Approach - 1
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
const int M = 1e9 + 7;
    int concatenatedBinary(int n) {
        int digits = 0;
        long long result = 0;
        for(int num = 1; num <= n; num++){
            if((num&(num-1)) == 0) digits++;
            result = ((result << digits) + num) % M;
        }
   return result; 
   }
};

//Approach - 2
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
const int M = 1e9 + 7;
    int concatenatedBinary(int n) {
        int digits = 0;
        long long result = 0;
        for(int num = 1; num <= n; num++){
           digits = log2(num)+1;
            result = ((result << digits) + num) % M;
        }
   return result; 
   }
};

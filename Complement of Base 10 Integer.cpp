//Approach -1
//T.C : O(log n)
class Solution {
public:
    int bitwiseComplement(int n) {
      if(n == 0) return 1;

      int temp = n;
      int xorbit = 0;

      while(temp){
        xorbit = (xorbit << 1) | 1;
        temp >>= 1;
      }

      return n ^ xorbit;
    }
};

//Approach - 2
//T.C : O(log n)
class Solution {
public:
    int bitwiseComplement(int n) {
      if(n == 0) return 1;

      int bits = log2(n) + 1;

      int mask = (1 << bits) - 1;
       //1 10 100 1000 10000-1
       
       return n ^ mask;
       }
};

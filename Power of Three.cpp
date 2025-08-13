//Aprroach - 1 - USing looping
//T.C : O(n)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false; // exclude zero and negatives
        while (n % 3 == 0) {      // keep dividing while divisible by 3
            n /= 3;
        }
        return n == 1; // if ended at 1 → it's a power of three
    }
};

//Approach - 2: using largest 3^x value
//T.C : O(log3(INT_MAX))
class Solution {
public:
    bool isPowerOfThree(int n) {
      if( n <= 0) return false;
      int x = 1;
      while(x <= INT_MAX/3){
        x*=3;
      }
      return x % n == 0;
    }
};

//Approach - 3: USing logrithmic approach
//T.C : O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)return false;
      double val = log10(n)/log10(3);
      return val == (int)val;
    }
};

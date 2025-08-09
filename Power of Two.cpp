//T.C : O(1)
class Solution {
public:
   bool isPowerOfTwo(int n) {
      long long Count = __builtin_popcountll((long long)n);
      if(Count == 1) return true;
      else return false;
    }
};

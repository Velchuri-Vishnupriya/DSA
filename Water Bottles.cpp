//T.C : O(numBottles/numExchange)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
  int total = numBottles;
  int n = numBottles;
  while(n >= numExchange){
    total += n/numExchange;
    n = (n - ((n/numExchange)*numExchange) + n/numExchange);
  }
   return total; }
};

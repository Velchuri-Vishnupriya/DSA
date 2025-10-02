//T.C : O(numBottles + numExchange)
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int count = numBottles;
        int emptyBottles = numBottles;
        while(emptyBottles >= numExchange){//O(numBottles + numExchange)
            emptyBottles -= numExchange;
            count++;
            numExchange++;
            emptyBottles++;
        }
    return count;}
};

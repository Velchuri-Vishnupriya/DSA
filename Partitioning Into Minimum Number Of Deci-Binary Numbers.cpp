//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minPartitions(string n) {
        int maxEl = INT_MIN;
        for(char& ch : n){
            int digit = ch - '0';
            (digit > maxEl) ? maxEl = digit : maxEl = maxEl;
        }
        return maxEl;
    }
};

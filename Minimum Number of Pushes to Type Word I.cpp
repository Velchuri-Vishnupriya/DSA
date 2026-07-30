//T.C : O(n/8) ≈ O(n)
//S.C : O(1) 
class Solution {
public:
    int minimumPushes(string word) {
        int i = 0;
        int n = word.length();
        int costPerKey = 1;
        int totalCost = 0;

        while(i < n){
            int j = i+8;
            if(j < n){
                totalCost += (j-i)*costPerKey;
                costPerKey++;
            }
            if(j >= n){
                totalCost += (n-i)*costPerKey;
                break;
            }
            i = j;
        }
    return totalCost;
    }
};

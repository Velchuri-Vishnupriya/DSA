//T.C : O(n^2)
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& basket) {
        int n = basket.size();
        vector<bool> used(n,false); 
        int unplaced = 0;

        for (int fruit : fruits) {
            bool placed = false;
            for(int i = 0; i < n; i++){
                if(used[i]==false && basket[i] >= fruit){
                    used[i] = true;
                    placed = true;
                    break;
                }
            }
            if(placed == false) unplaced++;
        }
        return unplaced;
    }
};

//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        int total = 0;
        for(int i = 1; i < s.length(); i++){
            if(s[i] == s[i-1]){
                if(neededTime[i] < neededTime[i-1]){
                    s[i] = s[i-1];
                     total += neededTime[i];
                    neededTime[i] = neededTime[i-1];
                }
            else{
                total += neededTime[i-1];
            }
            }
        }
return total;
    }
};

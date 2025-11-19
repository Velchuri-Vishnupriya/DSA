//T.C : O(n*log M) M = max value of nums 
//S.C : O(1)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        while(true){
           //O(n) 
           auto idx = find(nums.begin(), nums.end(),original);
            if(idx != nums.end()){
                original*=2;
            }else{
                return original;
            } 
        }
        return 0;
    }
};

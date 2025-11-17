//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = -1;
        bool istrue = true;
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                if(prev == -1){
                    prev = i;
                    continue;
                }else{
                    (i-prev-1 >= k) ? istrue = true : istrue = false;
                    prev = i;
                }
                if(!istrue) return false;
            }
        }
   return true; }
};

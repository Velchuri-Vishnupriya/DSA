//T.C : O(n * log (max))
//S.C : O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int low = 1;
        int high = *max_element(begin(nums), end(nums));
        int n = nums.size();
        int ans = 0;
       // int hours = 0;
        while(low <= high){//O(log n)
            int k = low + (high - low)/2;
            long long hours = 0;
            for(int i = 0; i < n; i++){//O(n)
            hours += (long long)ceil((double)nums[i]/k);
            }

            if(hours <= h){
                ans = k;
                high = k - 1;
            }else{
                low = k + 1;
            }
        }
   return ans;
}
};

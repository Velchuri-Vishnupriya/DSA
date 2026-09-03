//T.C : O(3*n)~O(n)
//S.C : O(1)
class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int smallestOddEl = INT_MAX;
        int smallestEvenEl = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i]%2){
                smallestOddEl = min(smallestOddEl, nums[i]);
            }else{
                smallestEvenEl = min(smallestEvenEl, nums[i]);
            }
        }

        //making everything odd
        if(smallestOddEl != INT_MAX){
            bool answer = true;
            for(int i=0; i<n; i++){
                if(nums[i] % 2 == 0){
                    if(nums[i] - smallestOddEl <= 0){
                        answer = false;
                        break;
                    }
                }
            }
            if(answer)return true;
        }

        //making everything even
        if(smallestEvenEl != INT_MAX){
            bool answer = true;
            for(int i=0; i<n; i++){
                if(nums[i] % 2){
                    if(nums[i] - smallestOddEl <= 0){
                        answer = false;
                        break;
                    }
                }
            }
            if(answer)return true;
        }
    return false;
    }
};

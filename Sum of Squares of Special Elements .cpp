//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            int idx = i+1;
            if(n % idx == 0){
                result += (nums[i]*nums[i]);
            }
        }
    return result;
    }
};

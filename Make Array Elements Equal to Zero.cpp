//Simple Simulation
//T.C : O(n*m)
//S.C : O(n)
class Solution {
public:
bool check(vector<int>& nums, int count, int i, int dir){
    int idx = i;
    vector<int> temp = nums;

    while(idx >= 0 && idx < nums.size() && count > 0){
        if(temp[idx] != 0){
            temp[idx]--;
            dir *= -1;
            if(temp[idx] == 0){
                count--;
            }
        }
        idx += dir;
    }
return count == 0;
}
    int countValidSelections(vector<int>& nums) {
        int result = 0;
        int n = nums.size();

        int count = 0;//count of no.of of non-zero elements

        for(int i = 0; i < n; i++){
            if(nums[i] != 0) count++;
        }

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
if(check(nums, count, i, -1)) result++;
if(check(nums, count, i, 1)) result++;
            }
        }

   return result; }
};

//Optimized version
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> cumSum(n);
        
        cumSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            cumSum[i] = cumSum[i-1] + nums[i];
        }

        int result = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) {
                int leftSum = i > 0 ? cumSum[i-1] : 0;
                int rightSum = cumSum[n-1] - cumSum[i];
                
                if(leftSum == rightSum) {
                    result += 2;
                } 
                else if(abs(leftSum - rightSum) == 1) {
                    result += 1;
                }
            }
        }
        return result;
    }
};

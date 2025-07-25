//T.C : O(n)
class Solution {
public:
    int maxSum(vector<int>& nums) {
        //all ele unique
        int n = nums.size();
        if(n == 1) return nums[0];
       set<int> st;
       int sum = 0 ;
       int res = INT_MIN;
       for(int i = 0; i < n; i++){
st.insert(nums[i]); 
       }
       
       for(auto ele : st){
        sum += ele;
        res = max(res , sum );
        if(sum < 0) sum -= ele;
       }
return res;
       }
};

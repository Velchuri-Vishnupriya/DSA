//T.C : O(n * maxOR) -> This is with memoization , without memoization it would be 2^n and memoization need space complexity 
//S.C : O(n*maxOR)
class Solution {
public:
int n;
int maxOR = 0;
int t[17][1 << 9];
int solve(int i, int currOR, int maxOR, vector<int>& nums){
    //Base case
    if(i >= n){
        if(currOR == maxOR) return 1;
        else return 0;
    }

    if(t[i][currOR] != -1) return t[i][currOR];

    //take
   int take =  solve(i+1, currOR | nums[i], maxOR, nums);

    //not take
   int not_take = solve(i+1, currOR, maxOR, nums);

    return t[i][currOR] = take + not_take;
}
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
for(int& num : nums){
    maxOR |= num;
}
int currOR = 0;
memset(t, -1, sizeof(t));
return solve(0,currOR,maxOR,nums);
    }
};

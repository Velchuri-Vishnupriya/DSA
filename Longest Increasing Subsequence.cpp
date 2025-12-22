//Recursion + MEmoization
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
int n;
int t[2501][2501];

int solve(int i, int p, vector<int>& nums){
    if(i >= n) return 0; //no ele left to form LIS

    if(p != - 1 && t[i][p] != - 1) return t[i][p];

    //take
    int take = 0;
    if(p == -1 || nums[i] > nums[p] ){
    take = 1 + solve(i+1, i, nums);}

    //skip
    int skip = solve(i+1, p, nums);

    int ans = max(take, skip);

    if(p != -1) t[i][p] = ans;

    return ans;
}
    int lengthOfLIS(vector<int>& nums) {
    n = nums.size();
    memset(t,-1,sizeof(t));
    return solve(0,-1,nums);
    }
};

//Bottom - Up
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> t(n,1);
        //t[i] = LIS ending at ith idx

        int maxLIS = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    t[i] = max(t[i], t[j] + 1);
                }
            }
            maxLIS =max(maxLIS, t[i]);
        }
    return maxLIS;
    }
};

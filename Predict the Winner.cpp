//Recursion + Memoization Approach 1
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
int t[21][21];
int solve(int i, int j, vector<int>& nums){
    if(i > j)return 0;
    if(i == j)freturn nums[i];
    if(t[i][j] != -1)return t[i][j];
    int take_i = nums[i] + min(solve(i+2, j, nums),
    solve(i+1, j-1, nums));

    int take_j = nums[j] + min(solve(i, j-2, nums),
    solve(i+1, j-1, nums));

    return max(take_i, take_j);
}
    bool predictTheWinner(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(),0);
        int n = nums.size();
        memset(t, -1, sizeof(t));
        int player1 = solve(0, n-1, nums);
        int player2 = total_sum - player1;
        return player1 >= player2;
    }
};

//Predict the Winner
//Recursion + Memoization Approach 2
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
int t[21][21];
int solve(int i, int j, vector<int>& nums){
    if(i > j)return 0;
    if(i == j)return nums[i];
    if(t[i][j] != -1)return t[i][j];
    int take_i = nums[i] - solve(i+1, j, nums);

    int take_j = nums[j] - solve(i, j-1, nums);

    return max(take_i, take_j);
}
    bool predictTheWinner(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(),0);
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, n-1, nums) >= 0;
       
    }
};

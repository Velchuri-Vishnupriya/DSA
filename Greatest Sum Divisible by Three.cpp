//Approach - 1
//T.C : O(n) + O(k log k)+ O(m log m)  ~ O(n log n) k = size of rem1 m = size of rem 2
//S.C : O(n)
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> rem1, rem2;

        for (int num : nums) {
            sum += num;
            if (num % 3 == 1) rem1.push_back(num);
            else if (num % 3 == 2) rem2.push_back(num);
        }

        if (sum % 3 == 0) return sum;

        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());

        int result = 0;
        int remainder = sum % 3;

        if (remainder == 1) {

            int option1 = INT_MAX;
            if (rem1.size() >= 1)
                option1 = rem1[0];

            int option2 = INT_MAX;
            if (rem2.size() >= 2)
                option2 = rem2[0] + rem2[1];

            result = sum - min(option1, option2);
        } 
        else { // remainder == 2

            int option1 = INT_MAX;
            if (rem2.size() >= 1)
                option1 = rem2[0];

            int option2 = INT_MAX;
            if (rem1.size() >= 2)
                option2 = rem1[0] + rem1[1];

            result = sum - min(option1, option2);
        }

        return result;
    }
};

//Approach - 2 Recurrsion + Memoization
//T.C : O(n) 
//S.C : O(n)
class Solution {
public:
int solve(int i, int remain, vector<int>& nums, vector<vector<int>>& t){
    if(i >= nums.size()){
        if(remain == 0){
            return 0;
        }
        return INT_MIN;
    }

    if(t[i][remain] != -1){
        return t[i][remain];
    }

    int take = nums[i] + solve(i+1, (remain + nums[i])%3, nums, t);
    int skip = solve(i+1, remain, nums, t);

    return t[i][remain] = max(take, skip);
}
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> t(n, vector<int>(3,-1));

        return solve(0,0,nums,t);
    }
};

//Approach 3 Bottom - up
// T.C : O(n)
// S.C : O(n*3) = O(n)
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> t(n + 1, vector<int>(3, INT_MIN));

        // Base case
        t[n][0] = 0;
        t[n][1] = INT_MIN;
        t[n][2] = INT_MIN;

        for (int i = n - 1; i >= 0; i--) {
            for (int remain = 0; remain < 3; remain++) {
                int newRemain = (remain + nums[i]) % 3;

                int take = (t[i + 1][newRemain] == INT_MIN) 
                           ? INT_MIN 
                           : nums[i] + t[i + 1][newRemain];

                int skip = t[i + 1][remain];

                t[i][remain] = max(take, skip);
            }
        }
        return t[0][0];
    }
};


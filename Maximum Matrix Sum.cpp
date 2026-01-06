//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long countNegatives = 0;
        long long minEl = LLONG_MAX;
        long long maxSum = 0;
        for(auto& row : matrix){
            for(auto& num : row){
                if(num < 0){
                    countNegatives++;
                }
                minEl = min(minEl, 1LL*abs(num));
                maxSum += (1LL * abs(num));
            }
        }

        if(countNegatives % 2 == 0){
            return maxSum;
        }else{
           return maxSum -= (2*minEl);
        }
    return maxSum;
    }
};

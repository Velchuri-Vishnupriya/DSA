//Recursion + Memoization
//T.C : O(n*n*n)~O(n^3)
//S.C : O(n^2)
class Solution {
public:
int t[501][501];
int solve(int l, int r, vector<int>& cumSum){
    if(l >= r)return 0;
    if(t[l][r] != -1)return t[l][r];

    int score = 0;
    for(int mid=l; mid <=r-1; mid++){//O(n)
        int leftSum = cumSum[mid] - (l-1 >= 0 ? cumSum[l-1] : 0);
        int rightSum = cumSum[r] - cumSum[mid];

        if(leftSum < rightSum){
            score = max(score,
            solve(l, mid, cumSum)+leftSum);
        }else if(rightSum < leftSum){
            score = max(score,
            solve(mid+1, r, cumSum)+rightSum);
        }else{
            score = max({score, solve(l, mid, cumSum)+leftSum, solve(mid+1,r,cumSum)+rightSum});
        }
    }
    return t[l][r] = score;
}
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        memset(t, -1, sizeof(t));
        vector<int> cumSum(n,0);
        cumSum[0] = stoneValue[0];
        for(int i=1; i<n; i++){
            cumSum[i]=cumSum[i-1]+stoneValue[i];
        }

        return solve(0, n-1, cumSum);
    }
};

//Bottom-Up
//T.C : O(n*n*n)~O(n^3)
//S.C : O(n^2)
class Solution {
public:
int t[501][501];
int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        memset(t, 0, sizeof(t));
        vector<int> cumSum(n,0);
        cumSum[0] = stoneValue[0];
        for(int i=1; i<n; i++){
            cumSum[i]=cumSum[i-1]+stoneValue[i];
        }

        for(int l=n-1; l>=0; l--){
            for(int r=l+1; r<n; r++){
                int score = 0;
                for(int mid=l; mid <=r-1; mid++){//O(n)
                    int leftSum = cumSum[mid] - (l-1 >= 0 ? cumSum[l-1] : 0);
                    int rightSum = cumSum[r] - cumSum[mid];

                    if(leftSum < rightSum){
                        score = max(score,
                        t[l][mid]+leftSum);
                    }else if(rightSum < leftSum){
                        score = max(score,
                        t[mid+1][r]+rightSum);
                    }else{
                        score = max({score, t[l][mid]+leftSum, t[mid+1][r]+rightSum});
                    }
                }
                t[l][r] = score;
            }
        }
        return t[0][n-1];
    }
};

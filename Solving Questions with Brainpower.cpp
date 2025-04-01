//Recurrsion + memoization
//T.C:O(n)
//S.C:O(n)
class Solution {
public:
int n;
long long solve(int i,vector<vector<int>>&q,vector<long long>& t){
    if(i>=n) return 0;
    if(t[i]!=-1) return t[i];
    long long taken=q[i][0]+solve(i+q[i][1]+1,q,t);
    long long nottaken=solve(i+1,q,t);
    return t[i]=max(taken,nottaken);
}
    long long mostPoints(vector<vector<int>>& q) {
n=q.size();
vector<long long> t(n+1,-1);
return solve(0,q,t);
    }
};

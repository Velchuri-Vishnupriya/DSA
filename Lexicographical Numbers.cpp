//using Recurrsion
//T.C: O(n) {Each number is visited only once}
//S.C: O(log n) {Recurrsion stack space tree can go to maximum of size logn as digits of a number is logn}
class Solution {
public:
void solve(int& currentnum, int n,vector<int>& vec){
     if(currentnum > n) return;
     
     vec.push_back(currentnum);

for(int j=0; j<=9; j++){
    int newnum;
    newnum = currentnum * 10 + j;
    if(newnum > n) return;
    solve(newnum, n, vec);
}
return;
}
    vector<int> lexicalOrder(int n) {
        vector<int> vec;
        for(int i=1; i<=9; i++){
        solve(i,n,vec);
        }
            
    return vec;} 
};

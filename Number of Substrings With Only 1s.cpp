//T.C : O(n)
//S.C : O(1)
class Solution {
public:
int MOD = 1e9 + 7;
long long solve(long long n){
   return (long long )((n*(n+1))/2) % MOD;
}
    int numSub(string s) {
        long long  ones = 0;
        long long  res = 0;
        for(int i=0; i<s.length(); i++){
if(s[i]=='0'){
res = (res + solve(ones)) % MOD;
ones = 0;
}else{
    ones++;
}
        }

res = (res + solve(ones)) % MOD;

    return res;
    }
};

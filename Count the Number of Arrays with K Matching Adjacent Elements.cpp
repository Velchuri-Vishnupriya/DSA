//T.C:O(log(n-k-1))
//S.C:O(n)
int MOD = 1e9 + 7;
class Solution {
public:
//we write a function to apply ncr formula 
long long findPower(long long a,long long b){
    if(b==0) return 1;
    long long half = findPower(a,b/2);
    long long result = (half*half) % MOD;
    if(b %2 != 0) result=(result*a)%MOD;
    return result;
}
long long nCr(int n,int r,vector<long long>& factorial){
       //n!/((n-r)!*r!) % MOD
    long long numerator = factorial[n];
    long long a = findPower(factorial[n-r],MOD-2);//Fermat's Little Theorem;
    long long b = findPower(factorial[r],MOD-2);

    long long result =(((numerator*a)%MOD)*b) % MOD;
    return result;
}
    int countGoodArrays(int n, int m, int k) {
        vector<long long> factorial(n+1,1);
        for(int i=2; i<=n; i++){
            factorial[i]=(factorial[i-1]*i) % MOD;
        }      
        long long result = nCr(n-1,k,factorial);
//n-1Ck * m * (m-1)^(n-k-1)
        result = (result * m) % MOD;
        result = (result * findPower(m-1,n-k-1)) % MOD;
        return result;
    }
};

//T.C; O(n*log(logn))
//S.C: O(n);
class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        vector<bool> isprime(n,true);
        isprime[0]=isprime[1]=false;
        for(int i=2;i*i<=n-1;i++){
            if(isprime[i]==true){
                for(int j=2;i*j<=n-1;j++){ //O(log(logn))
                    isprime[i*j]=false;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;i++){
if(isprime[i]==true) count++;
        }
    return count;}
};

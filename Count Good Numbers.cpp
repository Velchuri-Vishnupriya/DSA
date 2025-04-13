//T.C:(log(n))
//S.C: O(1)
class Solution {
public:
    const int MOD = 1e9 + 7;

   int findpower(long long a,long long b){
    if(b==0) return 1;

    long long half=findpower(a,b/2);
    long long result=(half*half)%MOD;

    if(b%2==1){
        result=(result*a)%MOD;
    }

    return result;
   }

    int countGoodNumbers(long long n) {
    return (long long)findpower(5,(n+1)/2)*findpower(4,n/2)%MOD;
    }
};

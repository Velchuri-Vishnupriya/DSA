//Approach1
//T.C : O(log1000(n))
//S.C : O(1)
class Solution {
public:
#define ll long long
    ll countCommas(long long n) {
        ll result = 0;
        ll lower = 1000;
        ll commas = 1;

        while(lower <= n){
            ll upper = lower*1000-1;
            if(upper > n) upper = n;

            ll countNumbers = upper - lower + 1;
            result += (countNumbers*commas);
            lower*=1000;
            commas++;
        }
    return result;
    }
};

//Approach2
//T.C : O(log1000(n))
//S.C : O(1)
class Solution {
public:
#define ll long long
    ll countCommas(long long n) {
        ll result = 0;
        ll start = 1000;
        while(start <= n){
            result += (n - start + 1);
            start *= 1000;
        }
    return result;
    }
};

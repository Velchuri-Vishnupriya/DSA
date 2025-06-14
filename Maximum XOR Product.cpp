//T.C : O(1) -> once we iterate for 50 times and nxt for n times where n<50 , so in total constant time spce
//S.C : O(1) 
class Solution {
public:
typedef long long ll ;
static const int M = 1e9 + 7 ;
    int maximumXorProduct(long long a, long long b, int n) {
    ll xXora = 0;
    ll xXorb = 0;

    //49th Bit to nth bit 
     for(ll i=49; i>=n; i--){
bool a_ith_bit = ((a>>i) & 1) > 0;
bool b_ith_bit = ((b>>i) & 1) > 0;

if(a_ith_bit){
    //ith bit is 1
    xXora = (xXora^(1ll << i));
}

if(b_ith_bit){
    //ith bit is 1
    xXorb = (xXorb^(1ll << i));
}
    } 

    //for (n-1) th bit to 0th bit 
   for(ll i = n-1; i>=0; i--){
    bool a_ith_bit = ((a>>i) & 1) > 0;
bool b_ith_bit = ((b>>i) & 1) > 0;

if(a_ith_bit == b_ith_bit){
    xXora = (xXora ^(1ll << i));
     xXorb = (xXorb ^(1ll << i));
     continue;
}

if(xXora > xXorb) xXorb = (xXorb ^ (1ll << i));
else xXora = (xXora ^(1ll << i));
   }

   return ((xXora % M)  * (xXorb % M) % M ); }
};

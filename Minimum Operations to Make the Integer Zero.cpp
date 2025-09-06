//Approach - 1
class Solution {
public:
typedef long long ll;
    int makeTheIntegerZero(int num1, int num2) {
     int t =1;
     while (true){
    ll val = (ll)num1 - (ll)t * (ll)num2;
    if(val < 0) return -1;
    if(__builtin_popcountll(val) <= t && t <= val) return t; //builtin_popcount takes log(n) time - number of digits of number n
    t++;
     }
        return -1;
    }
};

//Approach - 2
class Solution {
public:
typedef long long ll;
    int makeTheIntegerZero(int num1, int num2) {
for(int t=1; t<=36; t++){
     ll val = (ll)num1 - (ll)t * (ll)num2;
    if(val < 0) return -1;
    if(__builtin_popcountll(val) <= t && t <= val) return t;
}
    return -1;}
};

//T.C : O(d)
//S.C : O(d)
class Solution {
public:
typedef long long ll;
    ll sumAndMultiply(int n) {
        string x = "";
        ll sum = 0;
        string s = to_string(n);
        for(auto& ch : s){
            if(ch - '0'){
                x += ch;
            }
            sum = sum + 1LL*(ch - '0');
        }
        ll x_ = (x.empty()) ? 0 : stoll(x);
        return x_*sum;
    }
};

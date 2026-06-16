//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(auto& ch : s){
            if(ch >= 'a' && ch <= 'z'){
                res += ch;
            }else if(ch == '*'){
                if(!res.empty()){
                    res.pop_back();
                }
            }else if(ch == '#'){
                res += res;
            }else{
                reverse(res.begin(), res.end());
            }
        }
    return res;
    }
};

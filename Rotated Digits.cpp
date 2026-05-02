//T.C : O(n*logd)
//S.C : O(1)
class Solution {
public:
unordered_set<int> st = {3,4,7};
bool goodInt(int n){
    string s = to_string(n);
    string s1 = s;
    int i = 0;
    for(auto& ch : s){
        int digit = ch - '0';
        if(st.find(digit) != st.end())return false;
        if(ch == '2') s1[i] = '5';
        if(ch == '5') s1[i] = '2';
        if(ch == '0' || ch == '1' || ch == '8') s1[i] = ch;
        if(ch == '6') s1[i] = '9';
        if(ch == '9') s1[i] = '6';
        i++;
    }
    return (s1 != s);
}
    int rotatedDigits(int n) {
        int count = 0;
        for(int i=1; i<=n; i++){
            count += goodInt(i);
        }
        return count;
    }
};

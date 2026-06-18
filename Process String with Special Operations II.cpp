//T.C : O(n)-> 2 Pass Sol
//S.C : O(1)
class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();

        long long L = 0;

        for(char& ch : s){
            if(ch == '*'){
                if(L > 0)L--;
            }else if(ch == '#'){
                L *= 2;
            }else if(ch == '%'){
                //reverse - no change in L;
                continue;
            }else{//'a' to 'z'
                L++;
            }
        }

        if(k >= L)return '.';

        for(int i = n-1; i>=0; i--){
            if(s[i] == '*') {L++; //no change in k just undo the before change
            }else if(s[i] == '%'){
                //no change in L  but K will change
                k = L-1-k;
            }else if(s[i] == '#'){
                L = L/2;
                k = (k >= L) ? k-L : k;
            }else{
                L--;
            }

            if(L == k){
                return s[i];
            }
        }
    return '.';
    }
};

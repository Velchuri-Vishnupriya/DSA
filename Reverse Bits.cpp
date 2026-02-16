//T.C : O(32) ~ O(1)
//S.C : O(32) ~ O(1)
class Solution {
public:
    int reverseBits(int n) {
    string s = "";

    while(n){
        s += ((n % 2) + '0');
        n /= 2;
    }

    while(s.length() < 32){
        s += '0';
    }

    //now string is already in reversed form

    int newNum = 0;
    for(int i = 0; i < 32; i++){
        if(s[i] == '1'){
            newNum |= (1 << (31-i));
        }
    }

    return newNum;
    }
};

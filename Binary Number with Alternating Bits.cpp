//Approach - 1
//T.C : O(n)
//S.C : O(logn)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s = "";
        while(n){
            int rem = n % 2;
            char ch = rem + '0';
            s += ch;
            n /= 2;
        }

        for(int i = 1; i < s.length(); i++){
            if(s[i] == s[i-1]) return false;
        }

        return true;
    }
};

//Approach - 2
//T.C : O(log2(n))
//S.C : O(log2(n))
class Solution {
public:
    bool hasAlternatingBits(int n) {
       bitset<32> b(n);
       int bits = log2(n);
       for(int i = 0; i < bits; i++){
        if(b[i] == b[i+1]) return false;
       } 
       return true;
    }
};

//Approach - 3
//T.C : O()
//S.C : O()
class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int result = n ^ (n >> 1);
        return (result & (result + 1)) == 0;
    }
};

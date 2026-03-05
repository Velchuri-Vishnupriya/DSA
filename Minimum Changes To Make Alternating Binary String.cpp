//Approach - 1
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(string s) {
        // First pattern: start with s[0]
        string s1 = "";
        int ops = 0;
        
        for(char& ch : s){
            if(s1.empty()){
                s1.push_back(ch);
            }
            else if(s1.back() == ch){
                ops++;
                if(ch == '0')
                    s1.push_back('1');
                else 
                    s1.push_back('0');
            }else{
                s1.push_back(ch);
            }
        }

        // Second pattern: start with opposite of s[0]
        int op1s = 0;
        string s2 = "";
        char expected = (s[0] == '0') ? '1' : '0'; //0
        
        for(char& ch : s){
            if(s2.empty()){
                    op1s++;
                    s2.push_back(expected);
            }
            else if(s2.back() == ch){
                op1s++;
                if(ch == '0')
                    s2.push_back('1');
                else 
                    s2.push_back('0');
            }else{
                s2.push_back(ch);
            }
        }
        
        return min(ops, op1s);
    }
};

//Approach-2
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minOperations(string s) {
       int start_with_1 = 0;
       int start_with_0 = 0;

       int n = s.length();

       for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            if(s[i] == '0'){
                start_with_1++;
            }else{
                start_with_0++;
            }
        }
        else{
              if(s[i] == '1'){
                start_with_1++;
            }else{
                start_with_0++;
            }
        }
       }
       return min(start_with_0, start_with_1);
    }
};

//Approach - 3
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minOperations(string s) {
       int start_with_0 = 0;

       int n = s.length();

       for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            if(s[i] == '1'){
                start_with_0++;
            }
        }else{
            if(s[i] == '0') start_with_0++;
        }
        }
       return min(start_with_0, (n - start_with_0));
    }
};

//Approach - 1
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool checkOnesSegment(string s) {
        bool found = false;
        for(int i = 0; i < s.length(); i++){
            if(found && s[i] == '1')return false;

            if(s[i] == '1'){
                while(i < s.length() && s[i] != '0'){
                    i++;
                }
                found = true;
            }
        }
        return true;
    }
};

//Approach - 2
//T.C : O(n); S.C : O(n)
//A string which starts with 1 and is contigious 1s type will not have 01 in it at all hence if a string has 01 in it return false
class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};

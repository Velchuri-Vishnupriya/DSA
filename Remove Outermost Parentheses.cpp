//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string result = "";
        for(auto& ch : s){
            if(ch == '('){
                if(count != 0)result.push_back(ch);
                count++;
            }else{
                count--;
                if(count != 0)result.push_back(ch);
            }
        }
        return result;
    }
};

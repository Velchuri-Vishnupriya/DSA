//Approach - 1
//T.C : O(n)
//S.C : O(n/2)~O(n)
class Solution {
public:
    int maxDepth(string s) {
    stack<char>st;
    int res = 0;
    for(char& ch : s){
        if(ch == '('){
            st.push('(');
        }else if(ch == ')'){
            st.pop();
        }
        res = max(res, (int)st.size());
    }
    return res;
    }
};

//Approach - 2 constant space
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxDepth(string s) {
    int result = 0;
    int openBrackets = 0;
    for(auto& ch : s){
        if(ch == '(')openBrackets++;
        else if(ch == ')')openBrackets--;
        result = max(result, openBrackets);
    }
    return result;
    }
};

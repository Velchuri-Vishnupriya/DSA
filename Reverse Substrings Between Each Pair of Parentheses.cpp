//Approach-1
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    string reverseParentheses(auto& s) {
        int n = s.size();
        stack<int> lastSkipLength;

        string result;

        for(char& ch : s){//O(n)
            if(ch == '('){
                lastSkipLength.push(result.length());
            }else if(ch == ')'){
                int l = lastSkipLength.top();
                lastSkipLength.pop();
                reverse(begin(result)+l, end(result));//O(n)
            }else{
                result.push_back(ch);
            }
        }
    return result;
    }
};


//Approach-2
//T.C : O(n+n)- two pass
//S.C : O(1)
class Solution {
public:
    string reverseParentheses(auto& s) {
        int n = s.size();
        stack<int> openBracketIdx;
        vector<int> door(n);
        //doo[i] = j -> from i u can go to j
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                openBracketIdx.push(i);
            }else if(s[i] == ')'){
                int j = openBracketIdx.top();
                openBracketIdx.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        string result;
        int flag = 1;
        for(int i=0; i<n; i+=flag){
            if(s[i] == '(' || s[i] == ')'){
                i = door[i];
                flag = -flag;//change the direction
            }else{
                result.push_back(s[i]);
            }
        }
    return result;
    }
};

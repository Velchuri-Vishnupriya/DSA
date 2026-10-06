//Approach-1 Recursion+Memoization
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
int t[101][101];
bool solve(int idx, int open, string& s, int n){
    if(idx == n){
        return open == 0;
    }
    if(t[idx][open] != -1)return t[idx][open];
    bool isValid = false;

    if(s[idx] == '*'){
        isValid |= solve(idx+1, open+1, s, n);
        isValid |= solve(idx+1, open, s, n);

        if(open > 0){
            isValid |= solve(idx+1, open-1, s, n);
        }
    }else if(s[idx] == '('){
        isValid = solve(idx+1, open+1, s, n);
    }else{
        if(open > 0){
            isValid = solve(idx+1, open-1, s, n);
        }
    }
    return t[idx][open] = isValid;
}
    bool checkValidString(string s) {
       int n = s.length();
       memset(t, -1, sizeof(t));
       return solve(0, 0, s, n);
    }
};

//Approach-2 Bottom Up
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
bool checkValidString(string s) {
int n = s.length();
vector<vector<bool>> t(n+1, vector<bool>(n+1, false));
t[n][0] = true;
for(int i=n-1; i>=0; i--){
    for(int open = 0; open <=n; open++){
        bool isValid = false;

        if(s[i] == '*'){
            isValid |= t[i+1][open+1];
            isValid |= t[i+1][open];
            if(open > 0){
                isValid |= t[i+1][open-1];
            } 
        }else if(s[i] == '('){
            isValid |= t[i+1][open+1];
        }else{
            if(open > 0){
                isValid |= t[i+1][open-1];
            }
        }
        t[i][open] = isValid;
    }
}
    return t[0][0];
    }
};

//Approach-3 Using Stack
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
bool checkValidString(string s) {
    int n = s.length();

    stack<int> openSt;
    stack<int> asterixSt;

    for(int i=0; i<n; i++){
        if(s[i] == '('){
            openSt.push(i);
        }else if(s[i] == '*'){
            asterixSt.push(i);
        }else{
            if(!openSt.empty()){
                openSt.pop();
            }else if(!asterixSt.empty()){
                asterixSt.pop();
            }else{
                return false;
            }
        }
    }
    while(!openSt.empty() && !asterixSt.empty()){
        int idx = openSt.top();
        openSt.pop();
        if(asterixSt.top() < idx)return false;
        else{asterixSt.pop();}
    }
    return openSt.empty();
    }
};

//Approach-4 Constant Space
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int open = 0;
        int close = 0;
        int n = s.length();
        
        //Left to Right - Check Open Brackets
        for (int i = 0; i < n; i++) {

            if (s[i] == '(' || s[i] == '*') {
                open++;
            } else {
                open--;
            }
                
            if (open < 0) {
                return false;
            }
        }

        //Right to Left - Check CLose Brackets
        for (int i = n - 1; i >= 0; i--) {
            
            if (s[i] == ')' || s[i] == '*') {
                close++;
            } else {
                close--;
            }
            
            
            if (close < 0) {
                return false;
            }
        }
        
        return true;
    }
};

//Approach -1 :
//T.S O(n) S.C O(n)
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) {
            return false; // Odd-length strings cannot form valid parentheses
        }

        stack<int> open;       // Stack for locked '('
        stack<int> openClose;  // Stack for flexible positions ('locked[i] == 0')

        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                openClose.push(i); // Flexible position
            } else if (s[i] == ')') {
                if (!open.empty()) {
                    open.pop(); // Match this ')' with a previous '('
                } else if (!openClose.empty()) {
                    openClose.pop(); // Use a flexible position to match
                } else {
                    return false; // No way to balance this ')'
                }
            } else if (s[i] == '(') {
                open.push(i); // Push the index of '('
            }
        }

        // Balance remaining '(' with flexible positions
        while (!open.empty() && !openClose.empty() && openClose.top() > open.top()) {
            open.pop();
            openClose.pop();
        }

        // If there are unmatched '(' left, the string is invalid
        return open.empty();
    }
};

//Approach-2
class Solution{
    public:
    bool canBeValid(string s, string locked){
        int n=s.length();
        if(n%2 !=0){return false;}

        int open=0;
        int close=0;
        int i=0; int j=n-1;
        while(i<n && j>=0){
            if(s[i]=='('||locked[i]=='0'){
                open++;
            }
            else{open--;}
             if(s[j]==')'||locked[j]=='0'){
                close++;
            }
            else{close--;}
            if(open<0 || close<0){return false;}
            i++;
            j--;
        
        }
        return true;
    }
};

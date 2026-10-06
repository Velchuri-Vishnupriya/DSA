//Approach - 1 - Using Stack
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int needed = 0;
        for(auto& ch:s){
            if(ch == '(')st.push(ch);
            else{
                if(!st.empty())st.pop();
                else{needed+=1;}
            }
        }
        needed+=st.size();
        return needed;
    }
};

//Approach - 2 - Using Constant Space
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int size = 0;
        int needed = 0;
        for(auto& ch:s){
            if(ch == '(')size++;
            else{
                if(size > 0)size--;
                else{needed+=1;}
            }
        }
        needed += size;
        return needed;
    }
};

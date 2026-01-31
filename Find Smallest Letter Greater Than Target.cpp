//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {set<char> st;
    for(auto& ch : letters){
        st.insert(ch);
    }
    for(auto& ch : st){
        if(ch > target) return ch;
    }
        return *st.begin();
    }
};

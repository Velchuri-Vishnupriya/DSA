//T.C : O(n * 26) ~ O(n)
//S.C : O(26)~O(1)
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st;
        for(auto& ch :brokenLetters){
            st.insert(ch);
        }
        int count = 0;
        string word = "";
        for(int i=0; i <= text.length(); i++){
            if(i == text.length() || text[i] == ' '){
            bool canMakeWord = true;
            for(auto& ch : st){
                if(word.find(ch) != string ::npos){
                    canMakeWord = false;
                    break;
                }
            }
            if(canMakeWord) count++;
            word = "";
            }
            else{
                word += text[i];
            }
        }
        return count;
    }
};

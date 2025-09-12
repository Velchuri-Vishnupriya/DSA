//T.C : O(n)
class Solution {
public:
bool isVowel(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;

    return false;
}
    bool doesAliceWin(string s) {
      int j = 0;
      int count  = 0;
      while(j < s.length()){
        if(isVowel(s[j])){
            count++;
           
        }
        j++;
      }
if(count == 0) return false;
      return true;
    }
};

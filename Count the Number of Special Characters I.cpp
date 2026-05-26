//T.C : O(n)
//S.C : O(26+26)~O(1)
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowerCase(26);
        vector<int> upperCase(26);

        for(char& ch : word){
            if(isupper(ch)){
                upperCase[ch - 'A']++;
            }
            else{
                lowerCase[ch - 'a']++;
            }
        }

        int count = 0;

        for(int i=0; i<26; i++){
            if(lowerCase[i] != 0 && upperCase[i] != 0)count++;
        }

        return count;
    }
};

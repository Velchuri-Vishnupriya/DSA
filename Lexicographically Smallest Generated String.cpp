//T.C : O(n*m)
//S.C : O(n+m-1)
bool isSame(string& word, string& s2, int i, int m){
    for(int j=0; j<m; j++){
        if(word[i+j] != s2[j])return false;
    }
    return true;
}
class Solution {
public:
    string generateString(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        int N = n + m -1;
        string word(N, '$');

        //Processing 'T'
        for(int i=0; i<n; i++){
            if(s1[i] == 'T'){
                for(int j=0; j<m; j++){
                    if(word[i+j] != '$' && word[i+j] != s2[j]){
                        return "";
                    }
                    word[i+j] = s2[j];
                }
            }
        }
        
        vector<bool> canChange(N, false);
        
        // fill remaining with 'a'
        for(int i=0; i<N; i++){
            if(word[i] == '$'){
                word[i] = 'a';
                canChange[i] = true;
            }
        }

        //Process 'F'
        for(int i=0; i<n; i++){
            if(s1[i] == 'F'){
                if(isSame(word, s2, i, m)){
                    bool changed = false;

                    for(int k = i+m-1; k >= i; k--){
                        if(canChange[k] == true){
                            word[k] = 'b';
                            changed = true;
                            break;
                        }
                    }

                    if(changed == false)return "";
                }
            }
        }

    return word;
    }
};

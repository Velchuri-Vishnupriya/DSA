//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public:
vector<vector<int>> checkCP(string& word){
    int n = word.length();

    vector<vector<int>> lcp(n, vector<int>(n,0));

    for(int i=0; i<n-1; i++){
        lcp[i][n-1] = (word[i] == word[n-1]) ? 1 : 0;

    }

    for(int i=0; i<n-1; i++){
        lcp[n-1][i] = (word[i] == word[n-1]) ? 1 : 0;
        
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = n-2; j >= 0; j--){
            if(word[i] == word[j]){
                lcp[i][j] = lcp[i+1][j+1] + 1;
            }
        }
    }
    return lcp;
}
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        string word(n, '$');

        for(int i=0; i<n; i++){
            //word[i] = ?
            for(int j=0; j<i; j++){
                if(lcp[j][i] != 0){
                    word[i] = word[j];
                    break;
                }
            }

            if(word[i] == '$'){
                vector<bool> forbidden(6,false);

                for(int j=0; j<i; j++){
                    if(lcp[j][i] == 0){
                        forbidden[word[j] - 'a'] = true;
                    }
                }
               for(int idx = 0; idx < 26; idx++){
                if(forbidden[i] != true){
                    word[i] = idx + 'a';
                    break;
                }
               }  
            }

            if(word[i] == '$') return "";

            return checkCP(word) == lcp ? word : "";
        }
    }
};

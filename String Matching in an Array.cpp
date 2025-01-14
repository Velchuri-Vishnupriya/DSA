//Naive Approach
class Solution {
public:
    vector<string> stringMatching(vector<string> &words) {
        vector<string> result;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break;
                }
            }
        }

        return result;
    }
};

//Using KMP Approach
 class Solution {
public:
void computeLPS(string pattern,vector<int>& lps){
    int M=pattern.length();
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<M){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len !=0){
                len=len-1;
            }
            else{
                lps[i]=0;
                i++;
            }

        }
    }
}
bool searchKMP(string pat, string txt){
    int N=txt.length();
    int M=pat.length();
    vector<int> lps(M,0);
    computeLPS(pat,lps);
    int j=0;
    int i=0;
    while(i < N){
        if(pat[j]==txt[i]){
            i++; j++;
        }
        if(j==M){
            return true;
        }
        else if(i<N && pat[j]!=txt[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else {
                i++;
            }
        }
    }
    return false;
}
    vector<string> stringMatching(vector<string>& words) {
        vector<string> answer; // To store the result
        int n = words.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue; // Skip if comparing the same word
             if(searchKMP(words[i],words[j])){
                answer.push_back(words[i]);
break;
             }
            }
        }

        return answer;
    }
};

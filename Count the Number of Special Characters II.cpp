//T.C : O(n)
//S.C : O(2*26)~O(1)
class Solution {
public:
typedef pair<int,int> P;
    int numberOfSpecialChars(string word) {
int n = word.length();
int count = 0;

vector<int> upper(26, -1);
vector<int> lower(26, -1);

for(int i=0; i<n; i++){
    if(islower(word[i])){
        lower[word[i] - 'a'] = i;
    }else{
        if(upper[word[i] - 'A'] == -1){
            upper[word[i] - 'A'] = i;
        }
    }
}

for(int i=0; i<26; i++){
    if(lower[i] != -1 && upper[i] != -1 &&
    lower[i] < upper[i])count++;
}
      return count;
    }
};

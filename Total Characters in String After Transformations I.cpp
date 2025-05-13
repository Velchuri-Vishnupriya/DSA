//Naive Approach (Time Limit Exceeded)
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
const int MOD = 1e9 + 7;
int j=1;
vector<char> alphabets;
for(int ch='a'; ch <= 'z'; ch++ ){
    alphabets.push_back(ch);
}
while(j <= t){
int n = s.length();
for(int i=0; i<n; i++){
    if(s[i]=='z') {s.replace(i,1,"ab");n++;}
    else{
        char ch = s[i];
        int idx = ch - 'a';
        idx++;
        ch = alphabets[idx];
        s[i]=ch;
    }
}
j++;
} 
   int length = (s.length() % MOD);
   return length; }
};

//Approach -2

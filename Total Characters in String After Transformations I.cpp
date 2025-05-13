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
//T.C : O(n + t*26)
//S.C : O(1) (vectors are of constant size)
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
const int M = 1e9 + 7;
int n = s.length();
vector<int> mp(26,0);

for(char& ch: s)
{
    mp[ch-'a']++;
} 

for(int count=1; count<=t; count++){
    vector<int>temp(26,0);
    for(int i=0; i<=25; i++){
        char ch= i + 'a' ;
        int freq = mp[i];

        if(ch != 'z'){
            temp[(ch+1) - 'a']=(temp[(ch+1)-'a']+freq) % M;
            }
            else{
                temp['a'-'a'] = (temp['a'-'a']+freq)%M;
                temp['b'-'a'] = (temp['b'-'a']+freq)%M;
            }
    }
    mp=move(temp); 
}
int result = 0 ;
for(auto& it: mp){
    result = (result + it)%M;
}
return result;}
};

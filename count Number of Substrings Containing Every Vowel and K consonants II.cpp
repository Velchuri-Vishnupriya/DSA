//Sliding Window
class Solution {
public:
bool isVowel(char ch){
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
}
    long long countOfSubstrings(string word, int k) {
      int n=word.length();
      unordered_map<char,int> mp;
      vector<int> nxtconst(n,0);
int lastidx=n;
for(int i=n-1;i>=0;i--){
    nxtconst[i]=lastidx;
    if(!isVowel(word[i])){lastidx=i;}
}
int i=0;
int j=0;
int cons=0;
long long res=0;
while(j<n){
    char ch=word[j];
    if(isVowel(ch)){mp[ch]++;}
    else{cons++;}

    //when cons>k shrink the window
    while(cons>k){
        char ch=word[i];
        if(isVowel(ch)){
            mp[ch]--;
            if(mp[ch]==0){mp.erase(ch);}
        }
        else{cons--;}
        i++;
    }

    while(i<n && mp.size()==5 && cons==k){
        int idx=nxtconst[j];
        res+=(idx-j);
        char ch=word[i];
            if(isVowel(ch)){
            mp[ch]--;
            if(mp[ch]==0){mp.erase(ch);}
        }
        else{cons--;}
        i++;
    }
    j++;
}
    return res;

    }
};

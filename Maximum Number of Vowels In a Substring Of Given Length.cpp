//Using Sliidng Window
//T.S: O(n)
//S.C: O(1)
class Solution {
public:
bool isvowel(char ch){
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
}
    int maxVowels(string s, int k) {
        int n=s.length();
        int i=0;
        int j=0;
        int vow=0;
        int currvow=0;
        while(j<n){
            if(isvowel(s[j])){
                currvow+=1;
            }
            if(j-i+1==k){
                vow=max(vow,currvow);
                if(isvowel(s[i])) currvow-=1;
                i++;
            }
            j++;
        }
        return vow;
    }
};

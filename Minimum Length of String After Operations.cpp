//Approach 1;
T.S : O(n)
S.C :O(1)
class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        vector<int> vec(26,0);
        int del=0;
        for(char& ch:s){
            int idx=ch-'a';
            vec[idx]++;
            if(vec[idx]>=3){
                vec[idx]-=2;
                del+=2;
            }
        }
        return n-del;
    }
};

//Aprroach-2
class Solution {
public:
    int minimumLength(string s) {
       vector<int> vec(26,0);
       for(char& ch:s){
        vec[ch-'a']++;
       }
       int result=0;
       for(int i=0;i<26;i++){
        if(vec[i]==0) continue;
        if(vec[i]%2==0) result+=2;
        else result+=1;
       }
       return result;
    }
};
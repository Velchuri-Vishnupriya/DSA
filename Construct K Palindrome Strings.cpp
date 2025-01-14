class Solution {
public:
    bool canConstruct(string s, int k) {
      int n=s.length();
      if(n<k){
        return false;
      } 
      if(n==k){return true;}
      vector<int> vec(26,0);
      for(char& ch: s){
        vec[ch-'a']++;
      }
      int oddCount=0;
      for(int i=0;i<26;i++){
        if(vec[i] %2!=0) oddCount++;
      }
      return oddCount<=k;
    }
};

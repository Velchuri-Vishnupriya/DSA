//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int> freq(26,0);
        int i=0;
        int j=0;
        int maxlen = 0;
        while(j < n){
            freq[s[j]-'a']++;
            while(freq[s[j]-'a'] > 2){
                    freq[s[i]-'a']--;
                    i++;    
            }
            maxlen = max(j-i+1, maxlen);
            j++;
        }
        return maxlen;
    }
};

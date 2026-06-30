//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3,0);
        int result = 0;
        int i=0;
        int j=0;
        int n=s.length();

        while(j < n){
            freq[s[j] - 'a']++;
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){//at most O(n)
                result += (n-j);
                freq[s[i]-'a']--;
                i++;
            }
            j++;
        }
    return result;
    }
};

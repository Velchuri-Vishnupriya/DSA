//T.C : O(n)
//S.C : O(26)~O(1)
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> frequency(26,0);
        for(auto& ch:text){
            frequency[ch - 'a']++;
        }
        int minEl = INT_MAX;
        for(int i=0; i<26; i++){
            char ch = i + 'a';
            int freq = frequency[i];
            if(ch == 'l' || ch == 'o'){
                minEl = min(freq/2, minEl);
            }else if(ch == 'b' || ch == 'a' || ch == 'n'){
                minEl = min(freq, minEl);
            }
        }
    return minEl;
    }
};

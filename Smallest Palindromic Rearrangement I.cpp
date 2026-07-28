//T.C : O(N)
//S.C : O(1)
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        for(auto& ch : s){//O(N)
            freq[ch-'a']++;
        }

        string left = "";
        string mid = "";

        for(int i=0; i<26; i++){//O(26)
            left += string(freq[i]/2, i + 'a');

            if(freq[i] % 2){
                mid += i+'a';
            }
        }
        string right = left;
        reverse(right.begin(), right.end());//O(N/2)

        return left+mid+right;
    }
};

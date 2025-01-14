/*Time complexity and space complexity:
Time Complexity: 𝑂(𝑚+𝑛)
m: Number of shift operations.
n: Length of the string s.
Space Complexity: O(n) */

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int>shift(n+1,0);
        for(auto& shiftop:shifts){
            int start=shiftop[0]; int end=shiftop[1]; int direc=shiftop[2];
            shift[start]+= (direc==1 ? 1 :-1);
            shift[end+1]-=(direc==1 ? 1 : -1);
        }
        int cumusum=0;
        for(int i=0;i<n+1;i++){
            cumusum+=shift[i];
            shift[i]=cumusum;
        }
        for(int i=0;i<n;i++){
            int netshift=(shift[i]%26 +26 ) % 26;
            s[i]='a' + (s[i]-'a'+netshift)%26;

        }
        return s;
    }
};

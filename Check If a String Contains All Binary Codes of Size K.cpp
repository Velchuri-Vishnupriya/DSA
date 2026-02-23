//T.C : O(n)
//S.C : O(2^k)
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;

        int n = s.length();

        for(int i = 0; i <= n - k; i++){
            string s1 = s.substr(i,k);
            st.insert(s1);
        }

        return st.size() == (1 << k);
    }
};

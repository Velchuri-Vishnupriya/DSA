//Approach-1
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<char> letters;
        for (int i = 0; i < n; i++) {
            letters.insert(s[i]);
        }
        int result = 0;
        for (char letter : letters) {
            int left_idx = -1;
            int right_idx = -1;
            for (int i = 0; i < n; i++) {  // Missing loop to iterate over `s`
                if (s[i] == letter) {  // Fixed comparison operator
                    if (left_idx == -1) {
                        left_idx = i;
                    }
                    right_idx = i;
                }
            }

            if (left_idx != -1 && right_idx != -1 && left_idx < right_idx) {  // Check for valid range
                unordered_set<char> st;
                for (int middle = left_idx + 1; middle <= right_idx - 1; middle++) {
                    st.insert(s[middle]);
                }
                result += st.size();  // Add to the existing result
            }
        }
        return result;
    }
};

//Approach-2
class Solution {
public:
    int countPalindromicSubsequence(string s) {
     int n = s.length();
        vector<pair<int, int>> indices(26, {-1, -1});
        
        for(int i = 0; i<n; i++) {
            char ch = s[i];
            int idx = ch-'a';
            
            if(indices[idx].first == -1) {
                indices[idx].first = i;
            }
            
            indices[idx].second = i;
        }
        
        
        int result = 0;
        for(int i = 0; i<26; i++) {
            if(indices[i].first == -1) {
                continue;
            }
            
            unordered_set<char> st;
            for(int middle = indices[i].first+1; middle <= indices[i].second-1; middle++) {
                
                st.insert(s[middle]);
                
            }
            
            result += st.size();
        }
        
        return result;
    }
};

//Approach - 1
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        
        if(n != goal.length()) return false;

        unordered_map<char, vector<char>> mp;

        // store ALL previous characters
        for(int i = 0; i < n; i++){
            char prev_char = s[(i - 1 + n) % n];
            mp[s[i]].push_back(prev_char);
        }

        // check for goal
        for(int i = 0; i < n; i++){
            char prev_char = goal[(i - 1 + n) % n];

            if(mp.find(goal[i]) == mp.end()) return false;

            // check if this prev_char exists in vector
            bool found = false;
            for(char c : mp[goal[i]]){
                if(c == prev_char){
                    found = true;
                    break;
                }
            }

            if(!found) return false;
        }

        return true;
    }
};

//Approach - 2
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
    if(s.length() != goal.length())return false;
    string s1 = s + s;
    return s1.contains(goal);
    }
};

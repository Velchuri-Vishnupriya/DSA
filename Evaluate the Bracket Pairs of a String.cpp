//T.C : O(n+m)
//S.C : O(n+m)
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();

        unordered_map<string, string> mp;

        for(auto& vec : knowledge){
            mp[vec[0]] = vec[1];
        }

        string result = "";
        int i=0;

        while(i < n){
            if(s[i] == '('){
                int j = s.find(')', i+1);
                string sub = s.substr(i+1, j-i-1);
                result += mp.count(sub) ? mp[sub] : "?"; 
                i = j;
            }else{
                result += s[i];
            }
            i++;
        }

    return result;
    }
};

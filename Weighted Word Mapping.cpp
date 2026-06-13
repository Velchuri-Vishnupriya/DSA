//T.C : O(n*w)
//S.C : O(1)
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s = "";
        for(auto& word : words){
            int sum = 0;
            for(auto& ch : word){
                int idx = ch - 'a';
                sum += weights[idx];
            }
            sum = abs((sum % 26) - 25);
            char ch = sum + 'a';
            s += ch;
        }
    return s;
    }
};

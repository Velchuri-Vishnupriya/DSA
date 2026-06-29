//T.C : O(M*N)
//S.C : O(1)
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int total = 0;
        for(auto& s: patterns){
            //if(word.find(s) != std::string::npos)total++;
            if(word.contains(s))total++;
        }
    return total;
    }
};
